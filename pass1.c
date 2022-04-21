#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(){
    FILE *input,*optab,*intmfile,*symtab;
    char la[10],opc[10],oper[10],h[10],code[10],mne[10];
    int hex,lc,startadd,len;
    input = fopen("input2.txt","r");
    optab = fopen("optab.txt","r");
    intmfile = fopen("intermediatefile.txt","w");
    symtab = fopen("symtab.txt","w");
    fscanf(input,"%s %s %s",la,opc,oper);
    if(strcmp(opc,"START")==0){
        startadd=(int)strtol(oper,NULL,16);
        lc=startadd;
        fprintf(intmfile,"%15s%10s%10s\n",la,opc,oper);
        fscanf(input,"%s %s %s",la,opc,oper);
    }
    else
        lc=0;
    while(strcmp(opc,"END")!=0){
        fprintf(intmfile,"%04X",lc);
        if(strcmp(la,"----")!=0){
            fprintf(symtab,"%5s%10X\n",la,lc);
        }
        while(!feof(optab)){
            fscanf(optab,"%s %s",code,mne);
            if(strcmp(code,opc)==0){
                lc+=3;
                break;
            }
        }
        rewind(optab);
        if(strcmp(opc,"WORD")==0)
            lc+=3;
        else if(strcmp(opc,"RESW")==0)
            lc+=3*atoi(oper);
        else if(strcmp(opc,"RESB")==0)
            lc+=atoi(oper);
        else if(strcmp(opc,"BYTE")==0)
            lc+=strlen(oper)-2;
        fprintf(intmfile,"%10s%10s%10s\n",la,opc,oper);
        fscanf(input,"%s %s %s",la,opc,oper);
    }
    fprintf(intmfile,"%04x%10s%10s%10s\n",lc,la,opc,oper);
    len=lc-startadd;
    printf("length of the program = %04X\n",len);
    fclose(input);
    fclose(optab);
    fclose(symtab);
    fclose(intmfile);
}
