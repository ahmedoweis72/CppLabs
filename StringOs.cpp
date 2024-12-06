#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

int StringOsLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') length++;
    return length;
}
void StringOsCopy(char destination[], char source[]){
    int i = 0;
    while(source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}
int StringOsCompare(char str1[], char str2[]){
    if(StringOsLength(str1) > StringOsLength(str2)){
        return 1;
    } else if(StringOsLength(str1) < StringOsLength(str2)){
        return -1;
    } else {
        for(int i=0;i<StringOsLength(str1);i++){
            if(str1[i] > str2[i]){
                return 1;
            } else if(str1[i] < str2[i]){
                return -1;
            }
        }
    }
    return 0;
}
void StringOsConcat(char s1[], char s2[]){
    int i = StringOsLength(s1), j = 0;
    while(s2[j] != '\0'){
        s1[i] = s2[j];
        i++; j++;
    }
    s1[i] = '\0';
}

class StringOs{
    char *str;

public:
    StringOs(){
        str = new char[1];
        str[0] = '\0';
    }
    StringOs(char *s){
        int length = StringOsLength(s);
        str = new char[length + 1];
        StringOsCopy(str, s);
    }
    StringOs(StringOs &source){
        int length = StringOsLength(source.str);
        str = new char[length + 1];
        StringOsCopy(str, source.str);
    }

    StringOs operator=(StringOs &source) {
        delete[] str;
        int length = StringOsLength(source.str);
        str = new char[length + 1];
        StringOsCopy(str, source.str);
        return *this;
    }
    int operator==(StringOs &source) {
        return StringOsCompare(str, source.str);
    }
    StringOs operator+(const StringOs& source){
        StringOsConcat(str, source.str);
        return str;
    }

    void print(){ cout << str << endl; }
    ~StringOs() { delete[] str; }
};


int main()
{
    StringOs s1("hello World");
    StringOs s2(s1);
    StringOs s3=s1;
    s1.print();
    s2.print();
    s3.print();
    int compate = s1==s2;
    cout << "compare: " << compate << endl;
    cout << "concat: ";
    (s1+" "+s2).print();

    return 0;
}