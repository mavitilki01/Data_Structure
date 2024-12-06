#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct node{
	int id;
	char name[50];
	char surname[50];
	int year;
	int ECTS;
	float grade;

	struct node *right;
	struct node *left; 
	
	int height;
}node;

node array[MAX];

int cnt=0;

//Array oluþturma-------------------------------------------------------------------
void createArray(int *cnt, node array[]){

	if(*cnt>=MAX){
		printf("Array is full!");
		return;
	}
	
	printf("Enter id: ");
	scanf("%d", &array[*cnt].id);
	printf("Enter name: ");
	scanf("%s", array[*cnt].name);
	printf("Enter surname: ");
	scanf("%s", array[*cnt].surname);
	printf("Enter year: ");
	scanf("%d", &array[*cnt].year);
	printf("Enter ECTS: ");
	scanf("%d", &array[*cnt].ECTS);
	printf("Enter grade: ");
	scanf("%f", &array[*cnt].grade);

	(*cnt)++;
}

void searchStudentArray(node array[],int cnt, int id){
	printf("Enter id: ");
	scanf("%d", &id);
	int i=0;
	for (i = 0; i < cnt; i++) {
        if (array[i].id == id) {
            printf("Name: %s\nSurname: %s\nYear: %d\nECTS: %d\nGrade: %.2f\n",
                   array[i].name, array[i].surname, array[i].year, array[i].ECTS, array[i].grade);
            return;
        }
    }
    printf("Id was not found.\n");
}

//BST oluþturma ---------------------------------------------------------------
node *createNode(int id){
	node *newNode=(node*)malloc(sizeof(node));
	newNode->id=id;
	printf("Enter name: ");
	scanf("%s", newNode->name);
	printf("Enter surname: ");
	scanf("%s", newNode->surname);
	printf("Enter year: ");
	scanf("%d", &newNode->year);
	printf("Enter ETCS: ");
	scanf("%d", &newNode->ECTS);
	printf("Enter grade: ");
	scanf("%f", &newNode->grade);
	
	newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
	return newNode;
}

node *insertBst(node* root, int id){
	if(root==NULL){
		return createNode(id);
	}
	
	if(id < root->id)
		root->left = insertBst(root->left, id);
	else
		root->right = insertBst(root->right, id);
	return root;
}


void searchStudentBst(node *root,int id){
	if(root==NULL){
		printf("Id was not found.\n");
		return;
	}
	else if(root->id == id){
		printf("Name: %s\nSurname: %s\nYear: %d\nECTS: %d\nGrade: %.2f\n",root->name,root->surname,root->year,root->ECTS,root->grade);
		return;
	}
	if(id < root->id)
		return searchStudentBst(root->left,id);
	return searchStudentBst(root->right,id);			
}

int heightBst(node *root){
	if(root==NULL)
		return -1;
	else{
		int leftH = height(root->left);
		int rightH =height(root->right);
		if(rightH > leftH)
			return rightH +1;
		else
			return leftH +1;
	}
}

//AVL oluþturma----------------------------------------------------

int getBalance(node *origin){
	if(origin==NULL)
		return 0;
	return height(origin->left) - height(origin->right);
}

int height(node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int maxValue(int a, int b) {
    return (a > b) ? a : b;
}

node* rightRotate(node* z) {
    node* temp = z->left;
    z->left = temp->right;
    temp->right = z;

    
    z->height = maxValue(height(z->left), height(z->right)) + 1;
    temp->height = maxValue(height(temp->left), height(temp->right)) + 1;

    return temp;
}

node* leftRotate(node* z) {
    node* temp = z->right;
    z->right = temp->left;
    temp->left = z;

   
    z->height = maxValue(height(z->left), height(z->right)) + 1;
    temp->height = maxValue(height(temp->left), height(temp->right)) + 1;

    return temp;}
    
node* leftRightRotate(node* z) {
    z->left = leftRotate(z->left); 
    return rightRotate(z); 
}

// Sað-Sol rotasyonu
node* rightLeftRotate(node* z) {
    z->right = rightRotate(z->right); // Saðý saða döndür
    return leftRotate(z); // Sonra sola döndür
}

node* insertToAVL(int id, node* tree) {
    // Eðer aðaç boþsa, yeni düðüm oluþturuluyor
    if (tree == NULL) {
        tree = createNode(id); // createNode fonksiyonu ile yeni düðüm oluþturuluyor
        return tree;
    }

    // Düðüm ekleme: solda veya saðda ekleme yapýyoruz
    if (id < tree->id)
        tree->left = insertToAVL(id, tree->left); // Sol alt aðaçta ekleme
    else if (id > tree->id)
        tree->right = insertToAVL(id, tree->right); // Sað alt aðaçta ekleme
    else
        return tree; // Ayný ID varsa, ekleme yapmýyoruz
    // Düðüm yüksekliðini güncelle
    tree->height = maxValue(height(tree->left), height(tree->right)) + 1;

    // Dengeyi kontrol et
    int balance = getBalance(tree);

    
    if (balance > 1 && id < tree->left->id)
        return rightRotate(tree);

    // Sol-Sað Durumu (left-right rotation)
    if (balance > 1 && id > tree->left->id)
        return leftRightRotate(tree);

    // Sað-Sað Durumu (single left rotation)
    if (balance < -1 && id > tree->right->id)
        return leftRotate(tree);

    // Sað-Sol Durumu (right-left rotation)
    if (balance < -1 && id < tree->right->id)
        return rightLeftRotate(tree);

    return tree; // Aðacýn dengeli hali geri döndürülüyor
}

void searchStudentAvl(node *tree, int id) {
    if (tree == NULL) {
        printf("Id was not found.\n");
        return;
    }

    if (id == tree->id) {
    	printf("Name: %s\nSurname: %s\nYear: %d\nECTS: %d\nGrade: %.2f\n",tree->name, tree->surname, tree->year, tree->ECTS, tree->grade);
		return;
    }
    if (id < tree->id) {
        searchStudentAvl(tree->left, id);  // Sol alt aðaca devam et
    } else {
        searchStudentAvl(tree->right, id);  // Sað alt aðaca devam et
    }
}




void main(){
	int choose, id, HeightBst;
	node *root=NULL;
	node *tree=NULL;
	
	
	while(1){
		printf("\nMain Menu\n1-Array\n2-Binary Serach Tree\n3-AVL Tree\n4-Exit\n\n");
		printf("Choose a stack type: ");
		scanf("%d", &choose);
		
		switch(choose){
			case 1:
				while(1){
					printf("1-Create Array\n2-Search a student\n3-Return Main Menu\n\n");
					printf("Choose one: ");
					scanf("%d", &choose);
					
					switch(choose){
						case 1:
							createArray(&cnt,array);
							break;
						case 2:
							searchStudentArray(array,cnt, id);
							break;
						case 3:
							break;
						default:
							printf("Wrong valid. Try again.\n");
							break;
					}
					if (choose == 3) break;
				}
				break;
			case 2:
				while(1){
					printf("1-Create BST\n2-Search a student\n3-Height\n4-Return Main Menu\n\n");
					printf("Choose one: ");
					scanf("%d", &choose);
					switch(choose){
						case 1:
							printf("Enter id: ");
							scanf("%d", &id);
							root = insertBst(root, id);
							break;
						case 2:
							printf("Enter id: ");
							scanf("%d", &id);
							searchStudentBst(root,id);
							break;
						case 3:
							HeightBst = heightBst(root);
							printf("Height: %d\n", HeightBst);
							break;
						case 4:
							break;
						default:
							printf("Wrong valid. Try again.");
							break;
					}
					if (choose == 4) break;
				}
				break;
			case 3:
				while(1){
					printf("1-Create AVL\n2-Search a student\n3-Height\n4-Return Main Menu\n\n");
					printf("Choose one: ");
					scanf("%d", &choose);
					switch(choose){
						case 1:
							printf("Enter id: ");
                			scanf("%d", &id);
                			tree = insertToAVL(id, tree);
							break;
						case 2:
							printf("Enter id: ");
        					scanf("%d", &id);
        					searchStudentAvl(tree, id);
							break;
						case 3:
							printf("Tree height: %d\n", height(tree));
							break;
						case 4:
							break;
						default:
							printf("Wrong valid. Try again.");
							break;
					}
					if (choose == 4) break;
				}
				break;
			case 4:
				exit(0);
			default:
				printf("Wrong valid. Try Again.");
		}
	}

	
}
