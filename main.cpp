#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "node.hpp"
#include <fstream>
#include <string>
using namespace std;

BSTNode* root = NULL; // this is the root of BST that is initially NULL

BSTNode* create_new_node(Truck val)//this function creates new nodes for BST.
{//it return a pointer to the newly created node.
    BSTNode* fresh_node=new BSTNode();//create a dynamic array to store all info of trucks.
    fresh_node->val=val;// that means the root will have a value of all info of type truck. freshnode is a pointer pointing towrds the root 
    fresh_node->left=NULL;//because a new node is created, left and right pointers will be initialized as NULL.
    fresh_node->right=NULL;
    return fresh_node; //now return fresh node that has been newly created.
}

BSTNode* populate(BSTNode* root, Truck val)
{

    if (root==NULL)//means we have the first entry
    {
        root=create_new_node(val);//this can be treated as a base case for recursion where we want to create a new node and then proceed to its linking to rest of the BST.
    }
    
    else if(val.regNo>=root->val.regNo)
    {
        root->right=populate(root->right, val);
    }
    else if(val.regNo<root->val.regNo)
    {
        root->left=populate(root->left, val);
    }
    return root;
}



// You have to define the functions below
void loadTrucks()
{
    string line;
    ifstream myfile ("Input.txt");
    if (myfile.is_open())
    {   string name,petrol,regNo,fullmileage,emptymileage;
        //create a truck type variable to store the info of 5 lines.
        Truck val;
        while ( getline (myfile,name) )
        {
          
          getline(myfile,petrol);
          getline(myfile,regNo);
          getline(myfile,fullmileage);
          getline(myfile,emptymileage);
           val = {name,stod(petrol),regNo,stoi(fullmileage),stoi(emptymileage)};
           root=populate(root,val); //root updated returned pointer
        }
       
        myfile.close();

    }
}

void updated_mile(BSTNode *root) 
{
	if(root == NULL) return;
    
	updated_mile(root->left);       //Visit left subtree
    // cout<<endl;
    // cout<<"driver: "<<root->val.driver<<endl;  //Print data
    // cout<<"petrol: "<<root->val.petrol<<endl;  //Print data
    // cout<<"reg no: "<<root->val.regNo<<endl;  //Print data
    // cout<<"full mileage : "<<root->val.fullMileage<<endl;  //Print data
    // cout<<"empty mileage: "<<root->val.emptyMileage<<endl;  //Print data
    // cout<<endl;
    double x;
    x=(double)60/(root->val.fullMileage) + (double)60/(root->val.emptyMileage);
    if (x<root->val.petrol)
    {
        root->val.petrol=root->val.petrol-x;
    }
	updated_mile(root->right);      // Visit right subtree
}

void print_asc(BSTNode *root,ofstream* myFile) 
{
	if(root == NULL) return;
    
	print_asc(root->left,myFile);      
    cout<<endl;
    cout<<"driver: "<<root->val.driver<<endl;  //Print data
    cout<<"petrol: "<<root->val.petrol<<endl;  //Print data
    cout<<"reg no: "<<root->val.regNo<<endl;  //Print data
    cout<<"full mileage : "<<root->val.fullMileage<<endl;  //Print data
    cout<<"empty mileage: "<<root->val.emptyMileage<<endl;  //Print data
    cout<<endl;
    *myFile<<endl;
    *myFile<<"driver: "<<root->val.driver<<endl;  //Print data
    *myFile<<"petrol: "<<root->val.petrol<<endl;  //Print data
    *myFile<<"reg no: "<<root->val.regNo<<endl;  //Print data
   *myFile<<"full mileage : "<<root->val.fullMileage<<endl;  //Print data
    *myFile<<"empty mileage: "<<root->val.emptyMileage<<endl;  //Print data
    *myFile<<endl;
	print_asc(root->right,myFile);      // Visit right subtree
    
}

void makeJourney()
{
    updated_mile(root);
}

void unloadTrucks()
{
    ofstream *myFile = new ofstream;
    (*myFile).open("Trip.txt");
    (*myFile)<<"This is difficult"<<endl;
    print_asc(root,myFile);
    (*myFile).close();
}

int main()
{
    loadTrucks();
    makeJourney();
    unloadTrucks();
    return 0;
}
