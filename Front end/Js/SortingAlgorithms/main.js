// 排序算法演示
const { bubbleSort, selectionSort, insertionSort, mergeSort, quickSort } = require('./sort');

const arr = [64, 34, 25, 12, 22, 11, 90];
console.log('原始数组:', arr);

console.log('冒泡排序:', bubbleSort([...arr]));
console.log('选择排序:', selectionSort([...arr])); 
console.log('插入排序:', insertionSort([...arr]));
console.log('归并排序:', mergeSort([...arr]));
console.log('快速排序:', quickSort([...arr]));