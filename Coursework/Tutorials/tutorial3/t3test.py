#!/usr/bin/python3
import os
import signal
import sys
import tempfile
import subprocess
import glob
import shutil
import re
import time
import csv
import threading

'''
This class takes the place of sys.stdout. It intercepts whatever is
being written to the console and writes it the console, a file, and
a local data structure.
In other words, whatever you print here or in your program also
prints to the file and to a list. The list can then be searched for 
proper output. 
'''
class Tee(object):
	def open(self, name, mode):
		sys.stdout.flush()
		self.file = open(name, mode)
		self.stdout = sys.stdout
		sys.stdout = self
	def close(self):
		sys.stdout = self.stdout
		self.file.close()
	def write(self, data):
		self.file.write(data)
		self.stdout.write(data)
	def flush(self):
		self.file.flush()
		self.stdout.flush()

def kill_proc(proc, timeout):
	# you must have done something wrong
	# to end up here
    timeout["value"] = True
    proc.kill()

# a run with timeout function 
def run_with_timeout(cmd, timeout_sec, stdinput):
    proc = subprocess.Popen(cmd,stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    timeout = {"value": False}
    timer = threading.Timer(timeout_sec, kill_proc, [proc, timeout])
    timer.start()
    (out, err) = proc.communicate(input = stdinput.encode("utf-8"))
    if len(out) < 1000:
        print(out.decode("utf-8"))
    else:
    	#wow you printed a lot of stuff
        print(out[:1000].decode("utf-8") + "...")
    timer.cancel()
    return proc.returncode, timeout["value"]

	
def run(cmd, time, stdinput=""):
	print("Running: {}\n".format(cmd))
	try:
		
		# just in case we will kill your process 
		# after <time> seconds
		res, timeout = run_with_timeout(cmd, time, stdinput)
	except:
		print("An exception occurred")
		print("{} test failed!".format(cmd))
		return 0
	if timeout:
		print("Taking too long, abort")
		print("Infinite loop?")
		return 0
	if res == 0:
		return 2
	else: 
		print("Program exited with non-zero status, test failed")
	return 0

def unzip_and_test(dirname, zipfile, outof):

	# Unzip the zip file. If you pass a '-nozip' flag, skip
	# If we attempt to unzip and fail, exit with 0 marks
	if zipfile == "*.zip":
		print("{}\n* Unzipping {}\n{}".format("*"*75, zipfile, "*"*75))
		sys.stdout.flush()
		status = subprocess.call(["unzip", "-n", zipfile])
		if status != 0:
			print("unzip exited with non-zero status")
			print("\n\n{stars}\n* Mark: {mark}/{outof}\n".format(stars="*"*75, mark=0, outof=outof))
			return
		
		
	#unzipping successful
	#switch to directory dirname
	os.chdir(dirname)
	sys.stdout.flush()
	print("\n{stars}\n* Compilation\n{stars}".format(stars="*"*75))
	
	# run the 'make clean' and 'make all' commands
	cmds = ["clean","all"]
	for c in cmds:
		cmd = ["make",c]
		print("Executing: {}".format(" ".join(cmd)))
		res = subprocess.call(cmd)
		sys.stdout.flush()
		if res:
			# make command produced an error
			# return with 0 marks
			print("make: non-zero exit status {}".format(res))
			print("\n\n{stars}\n* Mark: {mark}/{outof}\n".format(stars="*"*75, mark=0, outof=outof))
			return
		
	score = 0
	
	args = ["2023 9 30 1 2023 9 30 2 true",
		"2023 9 30 1 2023 9 29 3 true",
		"2023 9 26 2 2023 9 30 7 false",
		"2023 9 26 4 2023 9 30 2 false",
		"2023 8 30 2 2023 9 30 2 false",
		"2022 9 30 11 2023 9 30 12 false"]

	#total marks: 12
	
	
	for arg in args:
		score += run("./test2", 5, arg)

	# Arguments are in pairs. First argument is the Room parameter,
	# second is the criteria
	# Last boolean is what should be returned from isMatch
	args = ["King King 2 2 false false true",
		"Queen King 2 2 false false false",
		"King King 4 4 false false true",
		"King King 4 4 false true false",
		"King King 3 2 true true true",
		"King King 2 3 true true false"]
			
	for arg in args:
		score += run("./test1", 5, arg)

	#total marks: 12
	

	print("\n\n{stars}\n* Mark: {mark}/{outof}\n{stars}\n".format(stars="*"*75, mark=score, outof=outof))



	

def process_all():
	 
	zipfile = '*.zip'
	if len(sys.argv)>1:
		if sys.argv[1].find("-nozip")!=-1:
			zipfile = "nozip"
			
	t = Tee()
	
	t.open('results.txt', 'w')
	dirname = 'tutorial3'
	#dirname = '.'
	unzip_and_test(dirname,zipfile, 24)
		
	t.close()



if __name__ == "__main__":
	
	sys.stdout.flush()
	process_all()
	sys.stdout.flush()
	
