import { useState } from 'react';
import Board from './components/Board';
import ScoreBoard from './components/ScoreBoard';
import Controls from './components/Controls';

export default function App() {
  const [squares, setSquares] = useState(Array(9).fill(''));
  const [xIsNext, setXIsNext] = useState(true);
  const [scoreX, setScoreX] = useState(0);
  const [scoreO, setScoreO] = useState(0);
  const [winner, setWinner] = useState<string | null>(null);

  const handleClick = (index: number) => {
    if (squares[index] || winner) return;
    const newSquares = [...squares];
    newSquares[index] = xIsNext ? 'X' : 'O';
    setSquares(newSquares);
    setXIsNext(!xIsNext);
    checkWinner(newSquares);
  };

  const checkWinner = (squares: string[]) => {
    const lines = [
      [0,1,2],[3,4,5],[6,7,8],
      [0,3,6],[1,4,7],[2,5,8],
      [0,4,8],[2,4,6]
    ];
    for (let [a, b, c] of lines) {
      if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c]) {
        setWinner(squares[a]);
        if (squares[a] === 'X') setScoreX(prev => prev + 1);
        else setScoreO(prev => prev + 1);
        return;
      }
    }
  };

  const handleContinue = () => {
    setSquares(Array(9).fill(''));
    setWinner(null);
    setXIsNext(true);
  };

  const handleReset = () => {
    handleContinue();
    setScoreX(0);
    setScoreO(0);
  };

  return (
    <div className="flex flex-col justify-center items-center bg-black">
      <h1 className="text-white text-4xl mb-6">Tic Tac Toe</h1>
      <Board squares={squares} onClick={handleClick} />
      <ScoreBoard scoreX={scoreX} scoreO={scoreO} />
      <Controls winner={winner} onContinue={handleContinue} onReset={handleReset} />
    </div>
  );
}
