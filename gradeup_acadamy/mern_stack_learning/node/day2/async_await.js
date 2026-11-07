console.log("1. An async function always returns a Promise.");

console.log("2.await can only be used inside an async function.");

console.log("await waits for a Promise to settle inside the async function.");

console.log("await does not block the entire Node.js event loop. Instead, it only pauses the execution of the specific async function it is used inside, relinquishing control back to the event loop so it can continue processing other tasks.");

console.log("await paused only the enclosing async function.");


console.log("Synchronous Blocking Code (e.g., fs.readFileSync), it paused the entire single thread (Event Loop).");


function getStudent() {
    let success = true;
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if (!success) {
                reject('error is there');
            }
            resolve({
                id: 1,
                name: "Rahul"
            });
        }, 2000);
    });
}

async function displayStudent() {
    try {
        const student = await getStudent();
        console.log(student);
    } catch (error) {
        console.log("Error:", error);
    }
}

displayStudent();

