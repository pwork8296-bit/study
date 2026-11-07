const fs = require('fs');

console.log('1. Synchronous Main Line');

setImmediate(() => console.log('3. Check (setImmediate)'));

setTimeout(() => console.log('2. Timer (setTimeout)'), 0);

process.nextTick(() => console.log('4. Microtask (process.nextTick)'));

Promise.resolve().then(() => console.log('5. Microtask (Promise)'));

fs.readFile(__filename, () => {
    console.log('6. I/O Callback');
});

console.log('7. Synchronous End Line');
