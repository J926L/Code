const { bubbleSort, selectionSort, insertionSort, mergeSort, quickSort } = require('./sort');

function testSortAlgorithm(sortFn, name) {
  const testCases = [
    [],
    [1],
    [1, 2, 3],
    [3, 2, 1],
    [5, 3, 8, 4, 6],
    [64, 34, 25, 12, 22, 11, 90]
  ];

  console.log(`\n测试 ${name} 算法:`);
  testCases.forEach((arr, i) => {
    console.log(`测试用例 ${i + 1}:`);
    console.log('输入:', arr);
    console.log('输出:', sortFn([...arr]));
  });
}

testSortAlgorithm(bubbleSort, '冒泡排序');
testSortAlgorithm(selectionSort, '选择排序');
testSortAlgorithm(insertionSort, '插入排序');
testSortAlgorithm(mergeSort, '归并排序');
testSortAlgorithm(quickSort, '快速排序');