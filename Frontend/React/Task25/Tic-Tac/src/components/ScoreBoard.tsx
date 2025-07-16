type ScoreBoardProps = {
  scoreX: number;
  scoreO: number;
};

export default function ScoreBoard({ scoreX, scoreO }: ScoreBoardProps) {
  return (
    <div className="flex justify-center gap-10 text-white mt-4">
      <div>Player 1 (X)<br />Score: {scoreX}</div>
      <div>Player 2 (O)<br />Score: {scoreO}</div>
    </div>
  );
}
