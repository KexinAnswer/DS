void AdjustDown(int array[], int size, int root)
{
  while (1) {
        // 判断 root 是否是叶子结点
            // 因为 堆是完全二叉树，所有没有左孩子一定没有右孩子
                // 又因为堆是顺序存储的
                    // 所以，找到左孩子的下标，如果左孩子的下标越界了，则没有左孩子
    int left = 2 * root + 1;
                 if (left >= size) { // 不要漏掉 ==
                       // 是叶子结点
                             return;
                                 }

                                     // 找到左右孩子最小的一个
                                         // 这里一定有左孩子，判断是否有右孩子
                                             int right = 2 * root + 2;
                                                 int min = left;
                                                     if (right < size // 有右孩子
                                                           && array[right] > array[left]) {  /* 右孩子的值小于左孩子*/
                                                                 min = right;
                                                                     }

                                                                         // 比较 array[min]  array[root]
                                                                             if (array[root] >= array[min]) {
                                                                                   return;
                                                                                       }

                                                                                           // 交换值
                                                                                               int t = array[root];
                                                                                                   array[root] = array[min];
                                                                                                       array[min] = t;
        
                                                                                                                      // 需要继续向下调整，以 min 作为结点
        //                                                                                                                  root = min;
        //                                                                                                                    }
        //                                                                                                                    }
        //
        //                                                                                                                    void PrintArray(int array[], int size) {
        //                                                                                                                      for (int i = 0; i < size; i++) {
        //                                                                                                                          printf("%d ", array[i]);
        //                                                                                                                            }
        //                                                                                                                              printf("\n");
        //                                                                                                                              }
        //                                                                                                                              kkkk
        //                                                                                                                      }
        //                                                                                                                    }
        //                                                                                }
  }
}
