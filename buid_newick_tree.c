#include <stdio.h>

int putshortline(int num,FILE *ptr){//printing shortline 
	
	if(num<0)
			return 0;

	else if(num==0)
			return 0;

	putc('-',ptr);
	num--;

	return putshortline(num,ptr);
}


FILE *Newick (FILE *fp ,FILE *ptr,int parantesis)//Building newick tree 
{
	char ch;
	ch=getc(fp);

	if(((ch)==EOF))
		return 0;

	if(ch=='('){ // taking parantesis information 
		parantesis++;
		return Newick(fp,ptr,parantesis);
	}

	if(ch==')'){
		parantesis--;
		return Newick(fp,ptr,parantesis);
	}

	if (ch==',') 
		return Newick(fp,ptr,parantesis);
	
		
	putshortline(parantesis,ptr);//printimg shortline depending on net parantesis situation
	putc(ch,ptr);//putting known character
	putc('\n',ptr);


	return Newick(fp,ptr,parantesis);

}

int main(){

	FILE *fp=fopen("input.txt","r"); //open file for read
	FILE *ptr=fopen("output.txt","w");//open file for write
	
	Newick(fp,ptr,0);//newick tree building and printing

	fclose(fp); //Close for reading file
	fclose(ptr);//Close for writing  file 
	
}
