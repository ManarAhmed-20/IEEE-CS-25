import Navbar from "./components/Navbar/Navbar";
import Card from "./components/Card/Card";
import { members } from "./data/members";

function App() {
  return (
    <div className="min-h-screen">
      <Navbar />
      <div className="p-10 flex flex-wrap justify-center gap-8">
        {members.map((member) => (
          <Card key={member.id} member={member} />
        ))}
      </div>
    </div>
  );
}

export default App;