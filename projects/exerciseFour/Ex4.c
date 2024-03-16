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

// struct data that contains the following values
struct Data {
    int num_of_lines;
    int ** the_data; 
    int * lines_len;
};

// I read the first number in file
int get_num_of_lines(FILE* fp){
    int num;
    fscanf(fp, "%d", &num);
    return num;
}

// I return the scanned int from file
int scan_next_int(FILE *fp){
    int num;
    fscanf(fp, "%d", &num);
    return num;
}

// tell me how many numbers I should read from file, and I insert them into an array pointer
void read_data(FILE *fp, int *arr, int n){
    for(int i =0; i < n; i++){
        arr[i] = scan_next_int(fp);
    }
}

// give me an array pointer and its length, and I find the max value in that array
int findMaxInArr(int *arr, int n){
    int max = arr[0];
    for(int i =0; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}


void findIndexOfRowWithMaxCol(int **tmpData, int * lines_len, int num_of_lines, int maxCol){
    // a copy of myData so that we find the correct index
    int originalData[num_of_lines][findMaxInArr(lines_len,num_of_lines)];
    for(int line = 0; line < num_of_lines; line++){
        for(int elem = 0; elem < lines_len[line]; elem++){
            originalData[line][elem] = tmpData[line][elem];
        }
    }

    // implementing insertionSort to sort each rows based on given column 
    int index = -1; // index is -1 if not found
    int k; // k is the column indexer

    // maxArr will contain all max col values in each row
    int maxArr[findMaxInArr(lines_len, num_of_lines)];

    // looping through all columns
    for(k = 0; k < maxCol; k++){
        // sorting
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
        // adding the max col value for each line
        // add the element found in row 0 col k
        maxArr[k] = tmpData[0][k];
    } // continue sorting

    // for each row, we check if we have the co-responding values
    for(int line = 0; line < num_of_lines; line++){
        // if we found it, we break, loop finishes
        if(index != -1){
            // breaking from the main loop
            break;
        }

        // for each line, we check the col values
        for(int elem = 0; elem < lines_len[line]; elem++){
            // if we find the value, we continue
            if (originalData[line][elem] == maxArr[elem]){
                // if we reached the row limit, we change index
                if(elem == lines_len[line] - 1){
                    index = line;
                }

            // if we have a wrong value, we go to the next line
            }else{
                // breaking from the most inner loop
                break;
            }
        }

    }
    // print the value, -1 if not found
    printf("%d\n", index);
}



int main(int argc, char const *argv[])
{
    struct Data myData; 
    // file pointer
    FILE* fp;
    
    // opening the file in read mode
    fp = fopen(argv[1], "r");

    // checking if file was loaded
    if(fp == NULL){
        printf("File does not exist\texiting ...\n");
        exit(0);
    }
    else{ // the file was opened successfully
        // get the first number in file
        myData.num_of_lines = get_num_of_lines(fp);

        // allocate memory num_of_lines * (int)
        myData.lines_len = malloc(myData.num_of_lines*sizeof(int));

        // allocate memory num_of_lines * (int *) exmp: the_data = {int *, int *, int *}
        myData.the_data = malloc(sizeof(int *)*myData.num_of_lines);


        // for each line scan n elements and save them in array
        for(int line = 0; line < myData.num_of_lines; line++){

            // num of elements to scan
            int numOfElements = scan_next_int(fp);

            // adding numofelements to lines_len array in Data Struct
            myData.lines_len[line] = numOfElements;

            // allocate memory for the size of elements
            int *array = malloc(sizeof(int)*numOfElements);;

            // assign each element to arr[index]
            read_data(fp, array, numOfElements);

            // put the array we just created into the data
            myData.the_data[line] = array;
        }


        // tmpData pointer => myData.the_data
        int **tmpData = myData.the_data;

        // Print the index of the row in which each element in its column is the biggest in the current column
        findIndexOfRowWithMaxCol(tmpData, myData.lines_len, myData.num_of_lines, findMaxInArr(myData.lines_len, myData.num_of_lines));

        // Close the opened File
        fclose(fp);
    }

    // free allocated memory
    free(myData.lines_len);
    for(int i = 0; i < myData.num_of_lines; i++){
        free(myData.the_data[i]);
    }
    free(myData.the_data);

    // return 0 in main marking the end of our program
	return 0;
}
