
console.log("A Promise represents the eventual completion or failure of an asynchronous operation.");

console.log("Promise has three states");

console.log("Pending=>Waiting, Fulfilled=>Success, Rejected=>Failure");


const myPromise = new Promise((resolve, reject) => {
    const success = true;

    if (success) {
        resolve("Student fetched successfully");
    } else {
        reject("Unable to fetch student");
    }
});

myPromise
    .then((result) => {
        console.log(result);
    })
    .catch((error) => {
        console.log(error);
    });



console.log("resolve() fulfills a Promise.");

console.log("reject() rejects a Promise.");

console.log(".then() handles fulfillment.");

console.log(".catch() handles rejection.");

console.log(".finally() runs after settlement, regardless of outcome.");