type SquareProps = {
  value: string;
  onClick: () => void;
};

export default function Square({ value, onClick }: SquareProps) {
  return (
    <button
      onClick={onClick}
      className={`w-20 h-20 sm:w-24 sm:h-24 border-2 text-4xl sm:text-5xl font-bold rounded-md
        ${value === 'X' ? 'text-red-500 border-red-500' : value === 'O' ? 'text-blue-500 border-blue-500' : 'border-gray-400'}
      `}
    >
      {value}
    </button>
  );
}
