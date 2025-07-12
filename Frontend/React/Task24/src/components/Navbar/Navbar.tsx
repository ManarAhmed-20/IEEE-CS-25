const Navbar = () => {
  return (
    <nav className="bg-white w-full h-16 py-4 px-12 flex flex-row justify-between drop-shadow-lg">
      <h1 className="text-2xl font-bold text-blue-600">TeamHub</h1>
      <ul className="flex flex-row gap-3 text-sm font-medium p-1.5">
        <li className="text-gray-600">Home</li>
        <li className="text-gray-600">Team</li>
        <li className="text-gray-600">About</li>
        <li className="text-gray-600">Contact</li>
      </ul>
      <button className="bg-blue-600 text-white w-24 rounded-3xl h-9">Join Us</button>
    </nav>
  );
};

export default Navbar;