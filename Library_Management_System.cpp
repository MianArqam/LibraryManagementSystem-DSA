#include <iostream>
using namespace std;

class student
{
public:
    string name;
    int age;
    int id;
};

class Node
{
public:

    student data;
    Node *next;
    Node *previous;
    Node(student data)
    {
        this->data.name = data.name;
        this->data.age = data.age;
        this->data.id = data.id;
        next = NULL;
        previous = NULL;
    }
};

class linkedlist
{
public:
    Node *head;
    linkedlist()
    {
        head = NULL;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "Name: " << temp->data.name << endl;
            cout << "ID: " << temp->data.id << endl;
            cout << "Age: " << temp->data.age << endl;
            cout << "--------------------" << endl;
            temp = temp->next;
        }
    }

    void addtail(student d)
    {
        Node *newnode = new Node(d);

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->previous = temp;
        }
    }

    void deleteNodeById(int idToDelete)
    {
        Node *current = head;
        Node *previousNode = NULL;

        // Traverse the list to find the node with the specified ID
        while (current != NULL && current->data.id != idToDelete)
        {
            previousNode = current;
            current = current->next;
        }

        // If the node with the specified ID is found
        if (current != NULL)
        {
            // If it's the head node
            if (previousNode == NULL)
            {
                head = current->next;
            }
            else
            {
                previousNode->next = current->next;
                if (current->next != NULL)
                {
                    current->next->previous = previousNode;
                }
            }

            // Delete the node
            delete current;
        }
        else 
        {
        	cout<<"no student with this id exists. "<<endl;
		}
        
    }
};
class bst_node{
    public:
        int student_id;
        string student_name;
        int student_age;
        bst_node* left;
        bst_node* right;
        bst_node(int id, string name, int age){
            student_id=id;
            student_name=name;
            student_age=age;
            left=NULL;
            right=NULL;
        }

};
class bst{
    public:
        bst_node* root;
        bst(){
            root=NULL;
        }
        void insert(int a, string b, int c){
            bst_node* newnode=new bst_node( a, b, c);
            if(root==NULL){
                root=newnode;
            }
            else{
                bst_node* temp=root;
                while(temp!=NULL){
                    if(b<temp->student_name){
                        if(temp->left==NULL){
                            temp->left=newnode;
                            break;
                        }
                        else{
                            temp=temp->left;
                        }
                    }
                    else{
                        if(temp->right==NULL){
                            temp->right=newnode;
                            break;
                        }
                        else{
                            temp=temp->right;
                            

                        }
                    }
                }
            }
        }
        void display(bst_node* temp){
            if(temp==NULL){
                return;
            }
            else{
                display(temp->left);
                cout<<temp->student_name<<" "<<temp->student_id<<" "<<temp->student_age<<endl;
                display(temp->right);
            }
        }
        void display(){
            display(root);
        }
        bst_node* search(int val){
            bst_node* temp=root;
            while(temp!=NULL){
                if(val==temp->student_id){
                    return temp;
                }
                else if(val<temp->student_id){
                    temp=temp->left;
                }
                else{
                    temp=temp->right;
                }
            }
            return NULL;
        }
  
};
class arr{
    public:
    int MAX_SIZE=100;
    int arr[100];
    int size=0;
    int val=1;

   void insert(int id,string name,int age){
       if(size==MAX_SIZE){
           cout<<"array is full"<<endl;
       }
       else{
              arr[size]=id;
              size++;
       }
   }
   void merge(int arr[],int l,int m,int r){
       int i,j,k;
       int n1=m-l+1;
       int n2=r-m;
       int L[n1],R[n2];
       for(i=0;i<n1;i++){
           L[i]=arr[l+i];
       }
       for(j=0;j<n2;j++){
           R[j]=arr[m+1+j];
       }
       i=0;
       j=0;
       k=l;
       while(i<n1 && j<n2){
           if(L[i]<=R[j]){
               arr[k]=L[i];
               i++;
           }
           else{
               arr[k]=R[j];
               j++;
           }
           k++;
       }
       while(i<n1){
           arr[k]=L[i];
           i++;
           k++;
       }
       while(j<n2){
           arr[k]=R[j];
           j++;
           k++;
       }
   }
    void mergesort(int arr[],int l,int r){
         if(l<r){
              int m=l+(r-l)/2;
              mergesort(arr,l,m);
              mergesort(arr,m+1,r);
              merge(arr,l,m,r);
         }
    }
    void display(){
        string name;
        mergesort(arr,0,size-1);
        for(int i=0;i<size;i++){
            cout<<"after Merge sort";
            cout<<arr[i]<<" ";
            
        }
        cout<<endl;
    }

   
};
class book{
    public:
    string Book_name;
    int Book_id;
    int Book_price;
    book(){}
    book(string name,int id,int price){
        Book_name=name;
        Book_id=id;
        Book_price=price;
    }
};
class stack{
public:
    int top=-1;
    int MAX_SIZE=100;
    book arr[100];
    
    void push(book b){
        if(top==MAX_SIZE-1){
            cout<<"stack is full"<<endl;
        }
        else{
            top++;
            arr[top]=b;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
        }
        else{
            top--;
        }
    }
    void display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i].Book_name<<" "<<arr[i].Book_id<<" "<<arr[i].Book_price<<endl;
        }
    }
};

class quueue{
    public:
    int front;
    int rear;
    int MAX_SIZE=100;
    book arr[100];
    
    quueue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(book b){
        if(rear==MAX_SIZE-1){
            cout<<"queue is full"<<endl;
        }
        if(rear == -1 && front == -1)
        {
            front++;
            rear++;
            arr[rear]=b;
        }
        else{
            rear++;
            arr[rear]=b;
        }
    }
    void dequeue(){
        if(front==rear){
            cout<<"queue is empty"<<endl;
        }
        else{
            front++;
        }
    }
    void display(){
        for(int i=front;i<=rear;i++){
            cout<<arr[i].Book_name<<" "<<arr[i].Book_id<<" "<<arr[i].Book_price<<endl;
        }
    }};
class librarymanagenemtsystem {
    private:
    
    public:
    
    void addstudent(bst &b,linkedlist &l,arr &a){
        int id;
        string name;
        int age;
        cout<<"enter id"<<endl;
        cin>>id;
        cout<<"enter name"<<endl;
        cin>>name;
        cout<<"enter age"<<endl;
        cin>>age;
        b.insert(id,name,age);
        cout<<"student added using bst"<<endl;
        l.addtail(student{name,age,id});
        cout<<"student added using linked list"<<endl;
        a.insert(id,name,age);
        cout<<"student added using array"<<endl;


    }
    //mergesort for array of students to sort them with respect to first letter of their name
    void merge(int arr[],int l,int m,int r){
       int i,j,k;
       int n1=m-l+1;
       int n2=r-m;
       int L[n1],R[n2];
       for(i=0;i<n1;i++){
           L[i]=arr[l+i];
       }
       for(j=0;j<n2;j++){
           R[j]=arr[m+1+j];
       }
       i=0;
       j=0;
       k=l;
       while(i<n1 && j<n2){
           if(L[i]<=R[j]){
               arr[k]=L[i];
               i++;
           }
           else{
               arr[k]=R[j];
               j++;
           }
           k++;
       }
       while(i<n1){
           arr[k]=L[i];
           i++;
           k++;
       }
       while(j<n2){
           arr[k]=R[j];
           j++;
           k++;
       } 
    }
    void mergesort(int arr[],int l,int r){
         if(l<r){
              int m=l+(r-l)/2;
              mergesort(arr,l,m);
              mergesort(arr,m+1,r);
              merge(arr,l,m,r);
         }
    }
    void display(int arr[],int size){
        mergesort(arr,0,size-1);
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    void addbook(quueue &q   ){
        string name;
        int id;
        int price;
        cout<<"enter book name"<<endl;
        cin>>name;
        cout<<"enter book id"<<endl;
        cin>>id;
        cout<<"enter book price"<<endl;
        cin>>price;
        book b(name,id,price);
        q.enqueue(b);
    }
};


int main()
{   arr a;
    bst b;
    linkedlist l;
    quueue q;
    stack s;
    librarymanagenemtsystem lms;
    int choice;
    
    while (true)
    {
        cout << "1. Add student" << endl;
        cout << "2. Delete student" << endl;
        cout << "3. Display students" << endl;
        cout << "4. merge sort" << endl;
        cout<<"5. add book"<<endl;
        cout<<"6. delete book"<<endl;
        cout<<"7. display book"<<endl;
        cout<<"8. Exit"<<endl;
              cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        
        case 1:
            lms.addstudent(b,l,a);
            break;
        case 2:
            int idToDelete;
            cout << "Enter the ID of the student to delete: ";
            cin >> idToDelete;
            l.deleteNodeById(idToDelete);
            break;
        case 3:
            cout << "Students: " << endl;
            cout<<"using array";
            a.display();
            cout<<"using linked list";
            l.print();
            break;
        case 4:
          if (a.size==0)
          {
                cout<<"array is empty"<<endl;
                break;
          }
          else
            cout<<"merge sort"<<endl;
            lms.mergesort(a.arr,0,a.size-1);
            a.display();
            break;
        case 5:
        if (q.rear==q.MAX_SIZE-1)
        {
            cout<<"queue is full"<<endl;
            break;
        }
        else
        
            cout<<"add book"<<endl;
            lms.addbook(q);
            break;
        case 6:
            cout<<"delete book"<<endl;
            q.dequeue();
            break;
        case 7:
            cout<<"display book"<<endl;
            q.display();
            break;
        case 8:
            exit(0);
            break;
            
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}

