import { useState, useEffect } from "react";
import Product from "./components/Product";

function App() {
  const [products, setProducts] = useState<ProductType[]>([]);

  interface ProductType {
  id: number;
  title: string;
  description: string;
  price: number;
  thumbnail: string;
}

  useEffect(() => {
    fetch("https://dummyjson.com/products?limit=10") 
      .then((res) => res.json())
      .then((data) => setProducts(data.products)) 
  }, []);

  return (
    <div className="w-full bg-blue-950 flex flex-col items-center justify-center p-5">
      <div className="w-full h-full flex flex-wrap gap-5 ">
        {products.map((product) => (
          <Product
            key={product.id}
            title={product.title}
            description={product.description}
            price={product.price}
            image={product.thumbnail}
          />
        ))}
      </div>
    </div>
  );
}

export default App;
