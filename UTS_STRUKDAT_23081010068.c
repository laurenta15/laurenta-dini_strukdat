#include <stdio.h>
#include <string.h>

struct Mahasiswa {
	char namaMahasiswa [50];
	char jenisKelain [10];
	struct mahasiswa *next;
};

void Mahasiswa *buatMahasiswa(char *namaMahasiswa, char *jenisKelamin) {
	Mahasiswa *new node = (Mahasiswa *)malloc(sideof(Mahasiswa));
	strcpy(new node->namaMahasiwa, namaMahasiswa);
	strcpy(new node->jenisKelamin, jenisKelamin);
	new node->next = NULL;
	return;
}

void tambahMahasiswa(Mahasiswa **head, char *namaMahasiswa, char *jenisKelamin){
	Mahasiswa *new node = buatMahasiswa(namaMahasiswa, jenisKelamin);
	if (*head == NULL) {
		*head = new node;
	}else{
		Mahasiswa *temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new node;
	}
} 

void tambahCindy(Mahasiswa **head, **head_Mahasiswi) {
	if (*head_Mahasiswi != NULL) {
		tambahMahasiswi("Cindy", "Perempuan");
		printf("Cindy tidak ikut lingkaran karena tidak ada mahasiswi");	
	}
}

void tambahIrsyadArsyad(Mahasiswa **head) {
	tambahMahasiswa("Irsyad", "Laki-Laki");
	tambahMahasiswa("Arsyad", "Laki-Laki");
}

int main() {
	Mahasiswa (Mahasiswa *head = NULL);
	Mahasiswi (Mahasiswi *head = NULL);
		
	tambahMahasiswa("Alan", "Laki-Laki");
	
	tambahCindy(Mahasiswa **head, **head_Mahasiswi);

	tambahIrsyadArsyad(Mahasiswa **head);
	
	printf("Lingkaran Mahasiswa setelah ALan keluar", Lingkaran Mahasiswa);
	
	return 0;
}
