type ControlsProps = {
  winner: string | null;
  onContinue: () => void;
  onReset: () => void;
};

export default function Controls({ winner, onContinue, onReset }: ControlsProps) {
  return (
    <div className="text-center mt-6">
      {winner && <div className="text-white text-xl mb-2">{winner} Wins!</div>}
      <button
        className=" text-gray-200 px-6 py-2 rounded-full mb-2 border"
        onClick={onContinue}
      >
        Continue
      </button>
      <br />
      <button
        className=" text-gray-200 px-6 py-2 rounded-full border"
        onClick={onReset}
      >
        Reset All
      </button>
    </div>
  );
}
