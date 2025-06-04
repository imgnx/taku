import React, { useState } from "react";
import webpackLogo from "@/assets/webpack.png";
import takuLogo from "@/assets/leaf.png";

const App = () => {
  const [count, setCount] = useState(0);
  const increment = () => setCount((count) => count + 1);
  const decrement = () => setCount((count) => count - 1);

  return (
    <main class="container mx-auto flex flex-col items-center justify-center text-center mt-42">
      <div className="grid grid-cols-2 gap-4 mb-8">
        <div>
          <img src={webpackLogo} className="w-full h-auto max-w-[225px] mx-auto" alt="Webpack logo" />
          <h1 className="heading">
            This is the <span>Home</span> page!
          </h1>
          <p>Click the buttons below to increment and decrement the count.</p>

          <p>Count: {count}</p>
          <button className="btn-primary" onClick={decrement}>
            Decrement
          </button>
          <button className="btn-secondary" onClick={increment}>
            Increment
          </button>
        </div>
        <div>
          <h1 class="text-[9rem] !my-0 relative inline leading-none">
            Tak
            <span class="inline relative">
              <img
                src={takuLogo}
                class="inline absolute bottom-[100%] transform -rotate-90 -mb-10"
                height="230"
                width="400"
              />
              u
            </span>
          </h1>
          <h2 class="text-6xl my-0">ChalkBox</h2>
          <h3 class="text-4xl text-gray-500 my-4 inline-block">Native WebView</h3>
          <p>Hello from Taku Native WebView!</p>
        </div>
      </div>
    </main>
  );
};

export default App;
