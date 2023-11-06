
to run our program for grayscale for example:
./filter -g images/yard.bmp out.bmp


FOR grayscale

It will take a colored photo and convert it into black and white
We will be using two for loops that will take height and width
We will need the byte or int values of each rgbt value
Then we will take the average of each and then put the value on each


for i = 0; i < height; i++
    for j = 0; j < width; j++
    int sum = images[i][j].rgbtBlue + images[i][j].rgbtGreen + images[i][j].rgbtRed;
    int average = (sum) / 3;
    images[i][j].rgbtBlue, images[i][j].rgbtGreen, images[i][j].rgbtRed = average;


FOR reflect

It will take a photo and reverse as if it is mirroring
We will be using two for loops that will take height and width
Then we will take the rgbt values and then put it on the opposite value
We will use a tmp to put the original on the opposite
For the opposite value we can use a int value to increment each row


for i = 0; i < height i++
    int index = 1;
    for j = 0; j < width; j++
        int tmp = images[i][j].rgbtBlue;
        images[i][j].rgbtBlue = images[height - index][j].rgbtBlue;
        images[height - index][j].rgbtBlue = tmp;
        int tmp = images[i][j].rgbtGreen;
        images[i][j].rgbtGreen = images[height - index][j].rgbtGreen;
        images[height - index][j].rgbtGreen = tmp;
        int tmp = images[i][j].rgbtRed;
        images[i][j].rgbtRed = images[height - index][j].rgbtRed;
        images[height - index][j].rgbtRed = tmp;
    index++;


FOR BLUR

We need to make every pixel in the picture blur out
We need four for loops
In order to do so we must go over 1 row, go under 1 row, go over 1 row
and over 1 column, go under 1 row and one column, go over 1 column,
go under 1 column
We need to check if that value exists
If so we put it to the red, blue, and green sums
and we increment counter by 1

afterwards we divide the sum and the count for r,g,b



FOR EDGES

We will need 4 for loops
We need the picture to be dark and have white lines as edges
We will keep the format of 1 under, over rows and columns just like in BLUR
We will need a GX and GY for red, green, and blue
At at certain point we will need to multiply that number by the value in the 3x3 table
from the Sobel Operator
Then we take that value square root and then add both gx and gy and then squareroot