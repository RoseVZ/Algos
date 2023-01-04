//the Node contains frequency, and a character
struct Node{
    char data;
    unsigned int freq;
    Node*left,*right;
    Node(char data,unsigned int freq,Node*left=0,Node*right=0){
        this->data=data;
        this->freq=freq;
        this->left=left;
        this->right=right;
    }
};

//comparator class 
  class comp{
      public:
       bool operator()(Node*l,Node*r){
     return l->freq >r->freq;
   }
  };
class Solution
{   
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
            //create a Min-Heap using priority queue
		     priority_queue<Node*,vector<Node*>,comp>pq;

             //push into the priority queue and create Node 
		     for(int i=0;i<f.size();i++)
		        pq.push(new Node(S[i],f[i]));


		     //do unitl there is only one element in priority queue
		     while(pq.size()>1)
             {
                //first element from queue as l ie least frequency Node
		         Node*l=pq.top();
                 pq.pop();
                //2nd least frequency  
		         Node*r=pq.top();
                 pq.pop();

                 //assign char value as '$' to new node create with sum of frequency of left and right
		         Node*top=new Node('$',l->freq+r->freq,l,r);

                 //push the new node on priority queue
		         pq.push(top);
		     }
		     vector<string>res;

             //the last element is passed as root and code is initalized to ""(empty string)  and pass the result vector
		     printHcode(pq.top(),"",res);
		     return res;
		}
		void printHcode(Node*root,string str,vector<string>&res)
        {
            //preorder traversal
		    if(!root)
                return;
		    if(root->data!='$') //if the Node reached is a character then push that code string into the result array
		        res.push_back(str);
		    printHcode(root->left,str+'0',res); //append 0 to tring if going left
		    printHcode(root->right,str+'1',res);//append 1 to string if going right
		}
};