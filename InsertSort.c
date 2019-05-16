void InsertSort(int array[], int size) {
  for (int i = 1; i < size; i++) {
        // 要为 array[i] 找位置
            int k = array[i];
                int j;
                    for (j = i - 1; j >= 0; j--) {
                          if (array[j] <= array[i]) {
                                  //memmove(array + j + 1, array + j + 2, i - j - 1);
                                          array[j + 1] = k;
                                                  break;
                                                        }
                                                            }
        
                                                                if (j == -1) {
                                                                      memmove(array + j + 1, array + j + 2, i - j - 1);
                                                                            array[j + 1] = k;
                                                                                }
                                                                                  }
                                                                                  }
                                                                }
                          }
                    }
  }
}
