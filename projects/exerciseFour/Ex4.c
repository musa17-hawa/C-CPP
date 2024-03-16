// 206598146

/*******************************************************************
* Copyright         : 2024 Musa Abu Alhawa
* File Name         : Ex4.c
* Description       : 
*                    
* Revision History :
* 
* Date              Author          Comments
* ---------------------------------------------------------------------------
* 05/03/2024        Musa Abu Alhawa     Created.
* 05/03/2024        Musa Abu Alhawa     Commit ID "a8d8fbc".
* 16/03/2024        Musa Abu Alhawa     Reading file and setting up Data struct
* 16/03/2024        Musa Abu Alhawa     Setting up filename.txt input as argv[], printing row index with all max elements 
*
/******************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct Data {
    int num_of_lines;
    int ** the_data; 
    int * lines_len;
};

int get_num_of_lines(FILE* fp){
    int num;
    fscanf(fp, "%d", &num);
    return num;
}

int scan_next_int(FILE *fp){
    int num;
    fscanf(fp, "%d", &num);
    return num;
}

void read_data(FILE *fp, int *arr, int n){
    for(int i =0; i < n; i++){
        arr[i] = scan_next_int(fp);
    }
}

int findMaxInArr(int *arr, int n){
    int max = arr[0];
    for(int i =0; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}


void sortData(int **tmpData, int * lines_len, int num_of_lines, int maxCol){
    int originalData[num_of_lines][findMaxInArr(lines_len,num_of_lines)];
    for(int line = 0; line < num_of_lines; line++){
        for(int elem = 0; elem < lines_len[line]; elem++){
            originalData[line][elem] = tmpData[line][elem];
        }
    }
    int index = -1;
    int k;
    int maxArr[findMaxInArr(lines_len, num_of_lines)]; 
    for(k = 0; k < maxCol; k++){
        int i, j;
        int rows = num_of_lines;
        for(i = 0; i < rows - 1; i++){
            for(j = 0; j < rows - i  - 1; j++){
                if (tmpData[j][k] < tmpData [j+1][k]){
                    int * tmpArr = malloc(sizeof(int)*(lines_len[j]));
                    tmpArr = tmpData[j] ;
                    tmpData[j] = tmpData[j+1];
                    tmpData[j+1] = tmpArr;
                }
            }
        }
        maxArr[k] = tmpData[0][k];
    }
    for(int line = 0; line < num_of_lines; line++){
        if(index != -1){
            break;
        }
        for(int elem = 0; elem < lines_len[line]; elem++){
            if (originalData[line][elem] == maxArr[elem]){
                if(elem == lines_len[line] - 1){
                    index = line;
                }
            }else{
                break;
            }
        }

    }
    printf("%d\n", index);

}


int findMaxInCol(int **tmpData, int n){
    int max = tmpData[0][0];
    for(int i = 0; i < n; i++){
        if (tmpData[i][0] > max){
            max = tmpData[i][0];
        }
    }
    return max;
}
int main(int argc, char const *argv[])
{
    struct Data myData; 
    // file pointer
    FILE* fp;
    // creating file using fopen() access mode "w"
    fp = fopen(argv[1], "r");
    // checking if file was loaded


    if(fp == NULL){
        printf("File does not exist\texiting ...\n");
        exit(0);
    }
    else{

        myData.num_of_lines = get_num_of_lines(fp);
        myData.lines_len = malloc(myData.num_of_lines*sizeof(int));
        myData.the_data = malloc(sizeof(int *)*myData.num_of_lines);

        // Main Code goes below.

        for(int line = 0; line < myData.num_of_lines; line++){
            int numOfElements = scan_next_int(fp);
            myData.lines_len[line] = numOfElements;
            int *array = malloc(sizeof(int)*numOfElements);;
            read_data(fp, array, numOfElements);
            myData.the_data[line] = array;
        }


        // sorting starts
        int **tmpData = myData.the_data;


        sortData(tmpData, myData.lines_len, myData.num_of_lines, findMaxInArr(myData.lines_len, myData.num_of_lines));
        int maxinCol = findMaxInCol(tmpData, myData.num_of_lines);

        fclose(fp);
    }
    free(myData.lines_len);
    for(int i = 0; i < myData.num_of_lines; i++){
        free(myData.the_data[i]);
    }
    free(myData.the_data);
	return 0;
}
