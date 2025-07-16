import { useState, useEffect, useRef } from "react";

const StopWatch = () => {
  const [time, setTime] = useState(0);
  const [isRunning, setIsRunning] = useState(false);
  const intervalRef = useRef<number | null>(null);

  useEffect(() => {
    if (isRunning) {
      intervalRef.current = setInterval(() => {
        setTime((prev) => prev + 1);
      }, 1000);
    } else if (intervalRef.current) {
      clearInterval(intervalRef.current);
    }

    return () => {
      if (intervalRef.current) clearInterval(intervalRef.current);
    };
  }, [isRunning]);

  const formatTime = (seconds: number) => {
    const hrs = Math.floor(seconds / 3600)
      .toString()
      .padStart(2, "0");
    const mins = Math.floor((seconds % 3600) / 60)
      .toString()
      .padStart(2, "0");
    const secs = (seconds % 60).toString().padStart(2, "0");

    return `${hrs}:${mins}:${secs}`;
  };

  return (
    <div className="flex flex-col items-center ">
      <h1 className="text-4xl font-medium mb-6 text-white">Stopwatch</h1>
      <div className="bg-indigo-400 rounded-2xl p-6 shadow-lg">
        <div className="w-64 h-64 rounded-full bg-gray-500 text-white flex items-center justify-center text-3xl font-mono">
          {formatTime(time)}
        </div>
        <div className="flex justify-center mt-6 gap-4">
          <button
            className="bg-blue-900 px-4 py-2 rounded text-white"
            onClick={() => setIsRunning((prev) => !prev)}
          >
            {isRunning ? "Pause" : "Start"}
          </button>
          <button
            className="bg-blue-900 px-4 py-2 rounded  text-white"
            onClick={() => {
              setIsRunning(false);
              setTime(0);
            }}
          >
            Reset
          </button>
        </div>
      </div>
    </div>
  );
};

export default StopWatch;
