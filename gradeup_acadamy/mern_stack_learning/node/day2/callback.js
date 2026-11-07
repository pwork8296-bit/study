console.log("A callback is a function passed as an argument to another function, which can invoke it later.");


const fs = require("fs");

fs.readFile("data.txt", "utf8", (error, data) => {
    if (error) {
        console.log(error);
        return;
    }

    console.log(data);
});


