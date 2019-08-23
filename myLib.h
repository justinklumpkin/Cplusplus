#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fstream>

using namespace std;
//const int n = 32;

void Isort(int ilist1[], const int n){
    int temp;

    for(int j = 0; j<n;j++){
        for(int k = j; k<n; k++){
            if(ilist1[j]>ilist1[k]){
                temp = ilist1[j];
                ilist1[j] = ilist1[k];
                ilist1[k] = temp;
            }
        }
    }
}

void Dsort(double dlist1[], const int n){
    double temp;

    for(int j = 0; j<n;j++){
        for(int k = j; k<n; k++){
            if(dlist1[j]>dlist1[k]){
                temp = dlist1[j];
                dlist1[j] = dlist1[k];
                dlist1[k] = temp;
            }
        }
    }
}

void Csort(char clist1[], const int n){
    char temp;

    for(int j = 0; j<n;j++){
        for(int k = j; k<n; k++){
            if(clist1[j]>clist1[k]){
                temp = clist1[j];
                clist1[j] = clist1[k];
                clist1[k] = temp;
            }
        }
    }
}

template<class Bubble>
void Bsort(Bubble ary[], const int n){
    Bubble temp;g

    for(int j = 0; j<n;j++){
        for(int k = j; k<n; k++){
            if(ary[j]>ary[k]){
                temp = ary[j];
                ary[j] = ary[k];
                ary[k] = temp;
            }
        }
    }
}
template<class Quick>
void Qsortt(Quick ary[], int p, int e){
    if(p != e){//more than 1 element
        if(p+1== e){//if 2 elements
            if(ary[p]>ary[e]){
                Quick temp = ary[p];
                ary[p]= ary[e];
                ary[e] = temp;
            }
        }else{
            int s = p+1, i=s,j=e;
            while(i<j){
                while((ary[i]<ary[p])&&(i<e)){
                    i++;
                }
                while((ary[j]>=ary[p])&&(j>s)){
                    j--;
                }
                if(i<j){
                    Quick temp = ary[i];
                    ary[i]= ary[j];
                    ary[j] = temp;
                }
            }
                if(i == e){
                    if(ary[i]<=ary[p]){
                        Quick temp = ary[i];
                        ary[i]= ary[p];
                        ary[p] = temp;
                    }

                    Qsortt(ary, p, i-1);
                }else if(j==s){
                    if(ary[j]<=ary[p]){
                        Quick temp = ary[j];
                        ary[j]= ary[p];
                        ary[p] = temp;
                    }

                    Qsortt(ary, j, e);
                }else{
                    Quick temp = ary[p];
                    ary[p]= ary[j];
                    ary[j] = temp;

                    Qsortt(ary, p, j-1);
                    Qsortt(ary, j+1, e);
                }
        }
    }
}

class Roman{
	public:
		Roman();		// default constructor  rStr = �Blank�, iStr = 0;
		Roman(string);	 	// constructs a Roman Numeral  given a String. Calls
                        //convertToInt() to assign the correct numeric value

		Roman(int);		// constructs a Roman numeral given a int. Calls
						//convertToStr to assign the correct numeric value
		void setStr(string);	// Sets the Roman Numeral String
		string getStr();		// Returns the Roman Numeral
		void setInt(int);		// Sets the Roman Numeral Value
		int getInt();		// Returns the Roman Numeral Value
		void displayProp();	// Displays the String and Integer Values of the Roman Numeral
        void convertToInt(string);	// coverts the string to its integer value
        void convertToStr(int);		// converts the integer to its string value
        string operator+(Roman);
        int operator-(Roman);
        int operator>(Roman);
        int operator>=(Roman);
        int operator< (Roman);
        int operator<= (Roman);
	private:
		string romanStr;
		int romanInt;
};

Roman::Roman(){// default constructor  rStr = �Blank�, iStr = 0;
    romanStr = "Blank";
    romanInt = 0;
}

Roman::Roman(string s){ 	// constructs a Roman Numeral  given a String. Calls
                        //convertToInt() to assign the correct numeric value
    romanStr = s;
    convertToInt(romanStr);
}

Roman::Roman(int num){// constructs a Roman numeral given a int. Calls
						//convertToStr to assign the correct numeric value
    romanInt = num;
    convertToStr(romanInt);
}

void Roman::setStr(string s){// Sets the Roman Numeral String
    romanStr = s;
}

string Roman::getStr(){// Returns the Roman Numeral
    return romanStr;
}

void Roman::setInt(int num){// Sets the Roman Numeral Value
    romanInt = num;
}

int Roman::getInt(){// Returns the Roman Numeral Value
    return romanInt;
}

void Roman::displayProp(){// Displays the String and Integer Values of the Roman Numeral
    cout<<"\n\nRoman Numerals: "<<getStr()<<"\n";
    cout<<"Hindu-Arabic Numerals: "<<getInt()<<"\n\n";
}

void Roman::convertToInt(string s){// coverts the string to its integer value
    int num = 0;
       // cout<<"RUN1\n";
    while(s.find("CM") != -1){
        num+=900;
        s.erase(s.find("CM"), 2);
    }

    while(s.find('M') != -1){
        num+=1000;
        s.erase(s.find("M"), 1);
    }

    while(s.find("CD") != -1){
        num+=400;
        s.erase(s.find("CD"), 2);
    }

    while(s.find('D') != -1){
        num+=500;
        s.erase(s.find("D"), 1);
    }

    while(s.find("XC") != -1){
        num+=90;
        s.erase(s.find("XC"), 2);
    }

    while(s.find('C') != -1){
        num+=100;
        s.erase(s.find("C"), 1);
    }

    while(s.find("XL") != -1){
        num+=40;
        s.erase(s.find("XL"), 2);
    }

    while(s.find('L') != -1){
        num+=50;
        s.erase(s.find("L"), 1);
    }

    while(s.find("IX") != -1){
        num+=9;
        s.erase(s.find("IX"), 2);
    }

    while(s.find('X') != -1){
        num+=10;
        s.erase(s.find("X"), 1);
    }

    while(s.find("IV") != -1){
        num+=4;
        s.erase(s.find("IV"), 2);
    }

    while(s.find('V') != -1){
        num+=5;
        s.erase(s.find("V"), 1);
    }

    while(s.find('I') != -1){
        num++;
        s.erase(s.find("I"), 1);
    }

    setInt(num);
}

void Roman::convertToStr(int num){// converts the integer to its string value
    string s = " ";

    while(num>=1000){
        num-=1000;
        s.insert(s.length()-1,"M");
    }

    while(num>=900){
        num-=900;
        s.insert(s.length()-1,"CM");
    }

    while(num>=500){
        num-=500;
        s.insert(s.length()-1,"D");
    }

    while(num>=400){
        num-=400;
        s.insert(s.length()-1,"CD");
    }

    while(num>=100){
        num-=100;
        s.insert(s.length()-1,"C");
    }

    while(num>=90){
        num-=90;
        s.insert(s.length()-1,"XC");
    }

    while(num>=50){
        num-=50;
        s.insert(s.length()-1,"L");
    }

    while(num>=40){
        num-=40;
        s.insert(s.length()-1,"XL");
    }

    while(num>=10){
        num-=10;
        s.insert(s.length()-1,"X");
    }

    while(num>=9){
        num-=9;
        s.insert(s.length()-1,"IX");
    }

    while(num>=5){
        num-=5;
        s.insert(s.length()-1,"V");
    }

    while(num>=4){
        num-=4;
        s.insert(s.length()-1,"IV");
    }

    while(num>=1){
        num--;
        s.insert(s.length()-1,"I");
    }

    setStr(s);
}

string Roman::operator+(Roman term2){
    return(getStr()+term2.getStr());//can type in main, but this is object oriented
}

int Roman::operator-(Roman term2){
    return(getInt()-term2.getInt());
}

int Roman::operator>(Roman term2){
    if(getStr().length() > term2.getStr().length()){
        return 1;
    }
    else if((getStr().length() == term2.getStr().length())&&(getInt() > term2.getInt())){
            return 1;
    }
    else{
        return 0;
    }
}
int Roman::operator>=(Roman term2){
    if(getStr().length() > term2.getStr().length()){
        return 1;
    }
    else if((getStr().length() == term2.getStr().length())&&(getInt() >= term2.getInt())){
            return 1;
    }
    else{
        return 0;
    }
}
int Roman::operator<(Roman term2){
    if(getStr().length() < term2.getStr().length()){
        return 1;
    }
    else if((getStr().length() == term2.getStr().length())&&(getInt() < term2.getInt())){
            return 1;
    }
    else{
        return 0;
    }
}
int Roman::operator<=(Roman term2){
    if(getStr().length() < term2.getStr().length()){
        return 1;
    }
    else if((getStr().length() == term2.getStr().length())&&(getInt() <= term2.getInt())){
            return 1;
    }
    else{
        return 0;
    }
}

//template<class Object>
//class Node{
//private:
//    Object data;
//    Node *next;
//public:
//    Node(Object d, Node *n){data = d; next = n;};
//    Object getData(){return data;};
//    Node* getNext(){return next;};
//    void setData(Object d){data=d;};
//    void setNext(Node *n){next = n;};
//};
//
//template<class Object>
//class List {
//private:
//    Node *first;
//public:
//    List(){first = NULL;};//
//    void add(Object num){
//        if (first == NULL){
//            first = new Node(num, NULL);
//        }else{
//            Node *current = first;
//            Node *temp1;
//            while((current->getNext()!=NULL)&&(num>current->getData())){
//                temp1 = current;
//                current = current->getNext();
//            }
//            if((current->getNext() == NULL)&&(num>current->getData())){
//                Node *temp = new Node(num, NULL);
//                current->setNext(temp);
//            }else if (current == first){
//                Node *temp = new Node(num, first);
//                first = temp;
//            }else{
//                Node *temp = new Node(num, current);
//                temp1->setNext(temp);
//            }
//        }
//    };
//    void remove(Object num){
////        if(first == NULL){
////            cout<<"Not in the list, there is no list\n\n";
////        }else
//        if (first->getNext() == NULL){
//            if (first->getData() == num){
//                first = NULL;
//            }else{
//                cout<<"Not in the list\n";
//            }
//        }else{
//            Node *current = first;
//            Node *temp1;
//
//            while ((current!=NULL)&&(current->getData()!=num)){
//                temp1 = current;
//                current = current->getNext();
//            }
//            if (current == NULL){
//                cout<<"Not in the list\n\n";
//            }else {
//                if(first->getData() == num){//&& thus(current == first)
//                    first = first->getNext();//create new first
//                    current->setNext(NULL);//the original first
//                }else{
//                    temp1->setNext(current->getNext());
//                }
//            }
//        }
//    };
//    void print(){
//        if(first!=NULL){
//            Node *current = first;
//            while(current != NULL){
//                cout<<setw(8)<<current->getData()<<endl;
//                current = current->getNext();
//            }
//        }else{
//            cout<<"Empty list";
//        }
//        cout<<endl<<endl;
//    };
//    //void trial();
//    void menu(){
//        int ans;
//        cout<<"Welcome to the Linked List Insert Sorter!\n\n";
//        do{
//            cout<<"1) Print\n2) Add\n3) Remove\n4) Exit\n";
//            cin>>ans;
//            cout<<endl<<endl;
//            if (ans == 1){
//                print();
//            }else if (ans == 2){
//                Object ins;
//                cout<<"What value would you like to add?\n";
//                cin>>ins;
//                add(ins);
//            }else if (ans == 3){
//                if(first == NULL){
//                    cout<<"There is no list\n\n";
//                }else{
//                    Object del;
//                    cout<<"What value would you like to remove?\n";
//                    cin>>del;
//                    remove(del);
//                }
//            }
//        }while (ans!=4);
//        cout<<"Come back soon!\n\n";
//    };
//};

class Enode{
private:
    char data;
    double p;
    Enode *left;
    Enode *right;
public:
    Enode(char d, Enode *l, Enode *r){
        data = d;
        if((d != '+')&&(d != '*')&&(d != '-')&&(d != '/')){
            p = data-'0';
        }else{
            p = 999;
        }
        left = l;
        right = r;
    };
    char getData(){return data;};
    double getP(){return p;}
    Enode* getLeft(){return left;};
    Enode* getRight(){return right;};
    void setData(char d){
        data=d;
        if((d != '+')&&(d != '*')&&(d != '-')&&(d != '/')){
            p = data-'0';
        }
    };
    void setP(double pr){p = pr;};
    void setLeft(Enode *l){left = l;};
    void setRight(Enode *r){right = r;};
};

class Etree {
private:
    Enode *root;
public:
    Etree(){root = NULL;};//
    int isop(char check){
        if((check == '+')||(check == '*')||(check == '-')||(check == '/')||(check == '$')){
            return 1;
        }else{
            return 0;
        }
    }
    int nextpar(int i1, string str2){//finds matching ')'
        int a = 1;
        i1++;
        while(a!= 0){
            if(str2[i1] == '('){
                a++;
            }else if (str2[i1] == ')'){
                a--;
            }
            i1++;
        }
        return i1;

    }
    void negation(string &str1){
        for(int i=0; i<str1.length();i++){
            if(str1[i] == '('){
                str1.erase(nextpar(i, str1),1);
                str1.erase(i,2);
                str1.insert(i,"$");
            }
        }
    }
    void EInsert(string &str, Enode *current){
        if(root == NULL){
            negation(str);
            root = new Enode(str[0],NULL,NULL);
            str.erase(0,1);
            EInsert(str, root);
        }else{
            Enode *temp = new Enode(str[0], NULL, NULL);
            if (current->getData()!='$'){
                current->setLeft(temp);
                str.erase(0,1);
                if(isop(temp->getData())){
                        EInsert(str, temp);
                }

                temp = new Enode(str[0], NULL, NULL);
            }
            current->setRight(temp);
            str.erase(0,1);
            if(isop(temp->getData())){
                EInsert(str, temp);
            }

        }
    };

    void print(Enode *n){
        if(n->getLeft()!=NULL){
//            cout<<"(";
            print(n->getLeft());
        }
        if(n->getData()!= '$'){
            cout<<n->getData()<<" ";
        }else{
            cout<<"-";
        }
        if(n->getRight()!=NULL){
            print(n->getRight());
//            cout<<")";
        }
    };

    double calculate(Enode *current){
        if(current->getData()=='+'){
            current->setP (calculate(current->getLeft())+calculate(current->getRight()));
        }else if(current->getData()=='-'){
            current->setP (calculate(current->getLeft())-calculate(current->getRight()));
        }else if(current->getData()=='*'){
            current->setP (calculate(current->getLeft())*calculate(current->getRight()));
        }else if(current->getData()=='/'){
            current->setP (calculate(current->getLeft())/calculate(current->getRight()));
        }else if(current->getData()=='$'){
            current->setP (-1*calculate(current->getRight()));
        }
        return (current->getP());
    };

    void menu(){
        int ans;
        cout<<setprecision(3);
        cout.setf(ios::showpoint|ios::fixed);
        do{
            cout<<"1) EInsert\n2) Print\n3) Calculate\n4) Exit\n";
            cin>>ans;
            cout<<endl;
            if (ans == 1){//einsert
                string ins;
                cout<<"Enter Expression:\n";
                cin>>ins;
                root = NULL;
                EInsert(ins, root);
                cout<<endl;
            }else if (ans == 2){//print
                if(root!=NULL){
                    cout<<"          ";
                    print(root);
                    cout<<endl;
                }else{
                    cout<<"There is no tree\n\n";
                }
            }else if (ans == 3){//calculate
                if(root == NULL){
                    cout<<"There is no tree\n\n";
                }else{
                    calculate(root);
                    cout<<"          "<<root->getP()<<endl<<endl;
                }
            }
        }while (ans!=4);
    };
};
