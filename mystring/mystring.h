#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
class myString{
  public:
    myString();
    myString(char *);
    myString(const myString &other);
    int Size()const;
    void setSize(int);
    void print();
    ~myString();
    void allocaStr(int len, char *&)const;
    myString& operator=(const myString &right);
    myString operator+(const myString &right);
  private:
    int length;
    char *ptr;
};


#endif // MYSTRING_H_INCLUDED
