#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void tranverse(node *head);
void insertNode(node **head, node *pPre, node *pNew);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void jumlahData(node *head);
void penjumlahanData(node *head);

//========================================================

int main()
{
  node *head;
  char pilih;

  head = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data di awal\n");
     printf("2. tambah data di tengah list\n");
     printf("3. tambah data di akhir list\n");
     printf("4. cetak isi list\n");
     printf("5. hapus data di awal list\n");
     printf("6. hapus data di tengah list\n");
     printf("7. hapus data di akhir list\n");
     printf("8. cari data\n");
     printf("9. jumlah data\n");
     printf("10. penjumlahan data\n");
     printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
     if (pilih == '1')
     		tambahAwal(&head);
     else if (pilih == '2')
			tambahData(&head);
	 else if (pilih == '3')
	 		tambahAkhir(&head);
     else if (pilih == '4') {
     		tranverse(head);
         	getch();
}
     else if (pilih == '5')	
     		hapusAwal(&head);
     else if (pilih == '6') 
     		hapusTengah(&head);
     else if (pilih == '7')
     		hapusAkhir(&head);
     else if (pilih == '8') 
     		cariData(head);
     else if (pilih == '9') {
     		jumlahData(head);
     		getch();
}
     else if (pilih == 10) {
     		penjumlahanData(head);
     		getch();
}
} while (pilih != 'q');
  
  return 0;
}

//========================================================

/*node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/

//========================================================

void tambahAwal(node **head){
  int bil;
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
  	  pNew->data = bil;
      pNew->next = NULL;
      //add before first logical node or to an empty list
	  pNew -> next = *head;
      *head = pNew;
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void tambahData(node **head){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  tranverse(*head);
  printf("\nposisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nbilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nalokasi memeori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->next = NULL;
     pNew -> next = pCur -> next;
     pCur -> next = pNew;
  }
}

//========================================================

void tambahAkhir(node **head){
	int bil;
	node *pNew, *pCur;
	
	system("cls");
	printf("masukan bilangan: ");
	scanf("%d", &bil);
	pNew = (node *)malloc(sizeof(node));
	
	if (pNew != NULL) {
		pNew->data = bil;
		pNew->next = NULL;
		
		if (*head == NULL) {
			*head = pNew;
		} else {
			pCur = *head;
			while (pCur->next != NULL) {
				pCur = pCur->next;
			}
			pCur->next = pNew;
		}
	} else {
		printf("Alokasi memori gagal");
		getch();
	}
}

//========================================================

void tranverse(node *head){
   //traverse a linked list
	node *pWalker;

   system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%d\t", pWalker -> data);
   	pWalker = pWalker -> next;
      printf(" -> ");
	}
   printf("NULL");
}

//========================================================

void insertNode(node **head, node *pPre, node *pNew){
    if (pPre == NULL){
       //add before first logical node or to an empty list
	    pNew -> next = *head;
       *head = pNew;
    }
    else {
       //add in the middle or at the end
       pNew -> next = pPre -> next;
       pPre -> next = pNew;
   }
}

//========================================================

void hapusAwal(node **head) {
	node *temp;
	
	if (*head != NULL) {
		temp = *head;
		*head = (*head)->next;
		free(temp);
		printf("Data awal berhasil dihapus. \n");
	} else {
		printf("List kosong. \n");
	}
}

//========================================================

void hapusTengah(node **head) {
	int target;
	
	printf("Masukan data yang akan dihapus: ");
	scanf("%d",&target);
	node *pCur = *head;
	node *pPrev = NULL;
	
	if (pCur != NULL && pCur->data == target) {
		*head = pCur->next;
		free(pCur);
		return;
	}
	while (pCur != NULL && pCur->data != target) {
		pPrev = pCur;
		pCur = pCur->next;
	}
	if (pCur == NULL) {
		printf ("Data tidak ditemukan. \n");
		return;
	}
	pPrev->next = pCur->next;
	free(pCur);
}

//========================================================

void hapusAkhir(node **head) {
	node *pCur = *head, *pPrev = NULL;
	
	if (*head == NULL) {
		printf("List kosong, tidak ada yang bisa dihapus\n");
		return;
	}
	if ((*head)->next == NULL) {
		free(*head);
		*head = NULL;
		return;
	}
	while (pCur->next != NULL) {
		pPrev = pCur;
		pCur = pCur->next;
	}
	pPrev->next = NULL;
	free(pCur);
}

//========================================================

void cariData(node *head) {
	int target;
	node *pCur = head;
	int found;
	
	system("cls");
	printf("Masukan data yang ingin dicari: ");
	scanf("%d", &target);
	
	while (pCur != NULL) {
		if (pCur->data == target) {
			printf("Data %d ditemukan dalam linked list. \n", target);
			found = 1;
			break;
		}
		pCur = pCur->next;
	}
	if(!found) {
		printf("Data %d tidak ditemukan dalam linked list. \n", target);
	}
	getch();
}

//========================================================

void jumlahData(node *head) {
	int count = 0;
	node *pCur = head;
	
	while (pCur != NULL) {
		count ++;
		pCur = pCur->next;
	}
	printf("jumlah data: %d\n", count);
}

//========================================================

void penjumlahanData(node *head) {
	int total = 0;
	node *pCur = head;
	
	if (head == NULL) {
		printf("List kosong, tidak ada yang bisa dijumlah \n");
	}
	while (pCur != NULL) {
		total += pCur->data;
		pCur = pCur->next;
	}
	printf("hasil penjumlahan data : %d\n", total);
}

//========================================================

