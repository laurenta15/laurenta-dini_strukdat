#include <stdio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *next;
    struct node *prev;
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
  node *pNew, *pCur;

  system("cls");
  printf("masukkan bilangan : ");
  scanf("%d", &bil);
  
  pNew = (node *)malloc(sizeof(node));
  if (pNew != NULL){
  	  pNew->data = bil;
      
	  if (*head ==NULL) {
	  	*head = pNew;
	  	pNew->next = pNew;
	  	pNew->prev = pNew;
	}else{
		pCur = *head;
		while (pCur->next != *head) {
			pCur = pCur->next;
		}
		pNew->next = *head;
		pNew->prev = pCur;
		pCur->next = pNew;
		(*head)->prev = pNew;
		*head = pNew;
	}

  }else{
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
     pNew -> next = pCur -> next;
     pNew->prev = pCur;
     
     if (pCur->next != NULL){
     	pCur->next->prev = pNew;
	 }
	 pCur->next = pNew;
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
		
		if (*head == NULL) {
			*head = pNew;
			pNew->next = pNew;
			pNew->prev = pNew;
		} else {
			pCur = *head;
			while (pCur->next != *head) {
				pCur = pCur->next;
			}
			pCur->next = pNew;
			pNew->prev = pCur;
			pNew->next = *head;
			(*head)->prev = pNew;
		}
	} else {
		printf("Alokasi memori gagal");
		getch();
	}
}

//========================================================

void tranverse(node *head){
   //traverse a linked list
	node *pCur;

   system("cls");
   if (head == NULL) {
   		printf("List kosong. \n");
   		return;
   }
   
   pCur = head;
   do {
 		printf("%d\t", pCur -> data);
   		pCur = pCur -> next;
	} while (pCur != head);
	
   printf("head \n");
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
	node *pCur;
	
	if (*head == NULL) {
		printf("List kosong, tidak ada yang bisa dihapus. \n");
		return;
	}
	node *temp = *head;
	if ((*head)->next == *head) {
		free(*head);
		*head = NULL;
	} else {
		node *last = (*head)->prev;
		*head = (*head)->next;
		(*head)->prev = last;
		last->next = *head;
		free(temp);
	}
		printf("Data awal berhasil dihapus. \n");
}

//========================================================

void hapusTengah(node **head) {
	int target;
	node *pCur;

	if (*head == NULL) {
		printf ("List kosong. \n");
		return;
	}
	
	printf("Masukan data yang akan dihapus: ");
	scanf("%d", &target);
	
	pCur = *head;
	
	if (pCur->next == *head && pCur->data == target) {
		free(pCur);
		*head = NULL;
		printf("node dengan data %d telah dihapus. List kosong. \n");
		return;
	}
	
	do {	
		if(pCur->data == target) {
			if (pCur == *head) {
				node *pLast = (*head)->prev;
				*head = pCur->next;
				(*head)->prev = pLast;
				pLast->next = *head;
			}else{
					pCur->prev->next = pCur->next;
					pCur->next->prev = pCur->prev;
			}
			free(pCur);
			printf("Data %d berhasil dihapus. \n", target);
			return;
		}
		pCur = pCur->next;
	}while (pCur != *head);
	
	printf("Data %d tidak ditemukan. \n", target);
}

//========================================================

void hapusAkhir(node **head) {
	
	if (*head == NULL) {
		printf("List kosong, tidak ada yang bisa dihapus\n");
		return;
	}
	if ((*head)->next == *head) {
		free(*head);
		*head = NULL;
		return;
	}
	node *pLast = (*head)->prev;
	pLast->prev->next = *head;
	(*head)->prev = pLast->prev;
	free(pLast);
	
	printf("Data akhir berhasil dihapus. \n");
}

//========================================================

void cariData(node *head) {
	int target;
	node *pCur = head;
	int found = 0;
	
	if (head == NULL) {
		printf("List kosong. \n");
		return;
	}
	
	system("cls");
	printf("Masukan data yang ingin dicari: ");
	scanf("%d", &target);
	
	do {
		if (pCur->data == target) {
			printf("Data %d ditemukan dalam linked list. \n", target);
			found = 1;
			break;
		}
		pCur = pCur->next;
	} while (pCur != head);
	
	if(!found) {
		printf("Data %d tidak ditemukan dalam linked list. \n", target);
	}
	getch();
}

//========================================================

void jumlahData(node *head) {
	int jumlah = 0;
	node *pCur = head;
	
	if (head == NULL) {
		printf("List kosong. \n");
		return;
	}
	
	do {
		jumlah++;
		pCur = pCur->next;
	} while (pCur != head);
	
	printf("jumlah data: %d\n", jumlah);
}

//========================================================

void penjumlahanData(node *head) {
	int total = 0;
	node *pCur = head;
	
	if (head == NULL) {
		printf("List kosong, tidak ada yang bisa dijumlah \n");
		return;
	}
	do {
		total += pCur->data;
		pCur = pCur->next;
	} while (pCur != head);
	
	printf("hasil penjumlahan data : %d\n", total);
}

//========================================================

