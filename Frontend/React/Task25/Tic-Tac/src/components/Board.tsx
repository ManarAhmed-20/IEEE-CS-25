import Square from './Square';

type BoardProps = {
  squares: string[];
  onClick: (index: number) => void;
};

export default function Board({ squares, onClick }: BoardProps) {
  return (
    <div className="grid grid-cols-3 gap-2">
      {squares.map((value, index) => (
        <Square key={index} value={value} onClick={() => onClick(index)} />
      ))}
    </div>
  );
}
