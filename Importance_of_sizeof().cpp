  // IMPORTANCE OF sizeof() function
  
  // Find Dimensions of a 2D array
  
  int main(int argc, char const *argv[])
  {
      int arr[6][5] = {
          {1,2,3,4,5},
          {1,2,3,4,5},
          {1,2,3,4,5},
          {1,2,3,4,5},
          {1,2,3,4,5},
          {1,2,3,4,5}
      };
    
      int rows = sizeof(arr)/sizeof(arr[0]);
      int cols = sizeof(arr[0])/sizeof(arr[0][0]);
    
      cout<<rows<<" "<<cols<<endl;
      return 0;
  }

// !! IMPORTANT - This doesn't work actually!!

// We need to use this

{
  int rows = matrix.size();
  int cols = matrix[0].size();
}
