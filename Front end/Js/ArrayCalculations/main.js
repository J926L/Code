// 数组计算程序
class ArrayCalculator {
  constructor(arr) {
    this.arr = arr;
  }

  // 计算数组总和
  sum() {
    return this.arr.reduce((acc, val) => acc + val, 0);
  }

  // 计算数组平均值
  average() {
    return this.sum() / this.arr.length;
  }

  // 计算数组最大值
  max() {
    return Math.max(...this.arr);
  }

  // 计算数组最小值  
  min() {
    return Math.min(...this.arr);
  }

  // 类型统计
  typeStats() {
    const stats = {
      int: 0,
      float: 0,
      other: 0
    };

    this.arr.forEach(num => {
      if (Number.isInteger(num)) {
        stats.int++;
      } else if (typeof num === 'number' && !Number.isNaN(num)) {
        stats.float++;
      } else {
        stats.other++;
      }
    });

    return stats;
  }
}

// 示例用法
const numbers = [1, 2.5, 3, 4.2, 5];
const calculator = new ArrayCalculator(numbers);

console.log('数组:', numbers);
console.log('总和:', calculator.sum());
console.log('平均值:', calculator.average());
console.log('最大值:', calculator.max());
console.log('最小值:', calculator.min());
console.log('类型统计:', calculator.typeStats());