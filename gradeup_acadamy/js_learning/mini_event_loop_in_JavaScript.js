// --- THE RUNTIME STORAGE ---
const callStack = [];
const macroTaskQueue = [];
const microTaskQueue = [];
let isEngineRunning = true;

// --- THE EVENT LOOP (The Traffic Controller) ---
function eventLoop() {
  // 1. Check if there is anything left to process
  if (callStack.length === 0 && macroTaskQueue.length === 0 && microTaskQueue.length === 0) {
    console.log("\n[Event Loop] All queues empty. Shutting down.");
    isEngineRunning = false;
    return;
  }

  console.log(`\n--- Loop Tick (Macro: ${macroTaskQueue.length} | Micro: ${microTaskQueue.length}) ---`);

  // PHASE 2: Execute ONE Macrotask from the front of the queue
  if (macroTaskQueue.length > 0) {
    const macroTask = macroTaskQueue.shift();
    console.log(`[Event Loop] Moving Macrotask to Call Stack: "${macroTask.name}"`);
    callStack.push(macroTask);
    
    // Execute the task
    executeCallStack();
  }

  // PHASE 3: Flush ALL Microtasks until the queue is completely empty
  if (microTaskQueue.length > 0) {
    console.log("[Event Loop] Call Stack empty. Flushing ALL Microtasks...");
    while (microTaskQueue.length > 0) {
      const microTask = microTaskQueue.shift();
      console.log(`[Event Loop] Moving Microtask to Call Stack: "${microTask.name}"`);
      callStack.push(microTask);
      
      executeCallStack();
    }
  }

  // Keep looping (simulating the continuous process)
  if (isEngineRunning) {
    setTimeout(eventLoop, 100); 
  }
}

// Helper to simulate the JS engine executing whatever is on the stack
function executeCallStack() {
  while (callStack.length > 0) {
    const currentTask = callStack.pop();
    currentTask.callback(); // Run the actual JavaScript code
  }
}

// --- MOCK RUNTIME WEB APIs (Simulating browser/Node background work) ---
const mockRuntime = {
  setTimeout: (callback, name) => {
    console.log(`[Web API] Timer started for: ${name}`);
    // Simulate background threading: when "done", push to macrotask queue
    macroTaskQueue.push({ name, callback });
  },
  queueMicrotask: (callback, name) => {
    console.log(`[Web API] Promise resolved, queueing Microtask for: ${name}`);
    // Promises bypass timers and go straight to the microtask queue
    microTaskQueue.push({ name, callback });
  }
};

// --- MAIN SCRIPT EXECUTION ---
console.log("[Main Script] Starting execution...");

// 1. Synchronous Code (Goes straight to stack)
console.log("[Main Script] Logging log 1");

// 2. Asynchronous Macrotask (e.g., setTimeout)
mockRuntime.setTimeout(() => {
  console.log("[Callback] Executing setTimeout 1");
}, "setTimeout 1");

// 3. Asynchronous Microtask (e.g., Promise.resolve().then)
mockRuntime.queueMicrotask(() => {
  console.log("[Callback] Executing Promise 1");
}, "Promise 1");

// 4. Another Macrotask
mockRuntime.setTimeout(() => {
  console.log("[Callback] Executing setTimeout 2");
}, "setTimeout 2");

console.log("[Main Script] Execution finished. Stack is now empty.");

// START THE REVOLVING EVENT LOOP
eventLoop();
 