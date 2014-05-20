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
    bool operator!=(const myString &right);
    bool operator!=(const char * right);
    bool operator==(const char* right);
    bool operator==(const myString &right);
    myString& operator=(const myString &right);
    myString operator+(const myString &right);
    int Compare(const myString &right);
    int Compare(const char *right);
  private:
    int length;
    char *ptr;
};

#endif // MYSTRING_H_INCLUDED
