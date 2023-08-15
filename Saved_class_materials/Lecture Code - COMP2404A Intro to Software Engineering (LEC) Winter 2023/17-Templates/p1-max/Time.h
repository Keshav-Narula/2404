#ifndef TIME_H
#define TIME_H

class Time
{
  friend ostream& operator<<(ostream&, const Time&);

  public:
    Time(int=0, int=0, int=0);
    void setTime(int=0, int=0, int=0);
    //we need this overloaded for consistency over different data types
    bool operator>(Time&)  const;

  private:
    int hours;
    int minutes;
    int seconds;
    int convertToSecs() const;
};

#endif
