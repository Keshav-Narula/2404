#ifndef TIME_H
#define TIME_H

class Time
{
  // Entered time: hh:mm:ss
  friend istream& operator>>(istream&, Time&);
  friend ostream& operator<<(ostream&, const Time&);
  public:
    Time(int=0, int=0, int=0);
    void setTime(int, int, int);
    //void print() const;

  private:
    int hours;
    int minutes;
    int seconds;
    int convertToSecs() const;
};

#endif
