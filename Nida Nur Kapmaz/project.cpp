#include <iostream>
#include <fstream>
#include <map>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono; //her seferinde uzun yazma diye

struct node
{
    int data; //data kısmı
    node *next; //başka bir node'a point eden pointer 
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()//constructor metodu
    {
        head = NULL;
        tail = NULL;
    }
    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)//ll boş ise
        {
            head = tmp;
            tail = tmp;
        }
        else//değil ise
        {
            tail->next = tmp;
            tail = tail->next;//tail -> tmp
        }
    }
    void sort(){//bubble
        node *i, *j;
        i=head;
        for(i=head; i!=NULL; i=i->next){//ll döngüsü
            for(j=i->next; j!=NULL; j=j->next){ //içinde datalaırn döndüğ kısım
                if(i->data < j->data){
                    swap(i->data,j->data);
                }
            }
        }
    }
    void print5(){ 
        node *i=head;
        int j=0;
        while(i!=NULL){
            if(j<5){
            cout<<i->data<<endl;
            i=i->next;
            j++;
            }else{
                break;
            }

        } 
    }
  
};

int main()
{

    int value;
    map<int,int> hasht; //hangi veri yapılarını alacağını yazdık
    fstream file1("input.txt");
    fstream file2("input2.txt");
    string line2;
    string line1;
    auto start = high_resolution_clock::now(); //başlangıç zamanı
    if(file1.is_open()){
        int i =0;
        while(getline(file1,line1)){
            value=stoi(line1);
            hasht.emplace(value,i); //sorted map yapar. 
            i++;
        }
    }
    int count =1;
    for (auto i = hasht.rbegin(); i != hasht.rend(); ++i) { 
        if (count>5){
            break;
        }
        cout << i->first << " in the line number "<< i->second << endl; 
        count++;

    }
    auto stop = high_resolution_clock::now(); //bitis zamanı
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << endl<<"hash insertion and listing top 5 elements took: " << duration.count() << " nanoseconds" << endl<<endl;
    

    start = high_resolution_clock::now();
    linked_list ll;//head=null tail=null


    if (file2.is_open()){
        while(getline(file2,line2)){
        value=stoi(line2);//str to int
        ll.add_node(value);
        }
    }
    ll.sort();
    ll.print5();


    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout <<endl<< "linked list insertion and listing top 5 elements took: " << duration.count() << " nanoseconds" <<endl<<endl;


    return 0;
}

