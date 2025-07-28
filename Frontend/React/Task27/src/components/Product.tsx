interface ProductProps {
  title: string;
  description: string;
  price: number;
  image: string;
}

function Product({ title, description, price, image }: ProductProps) {
    return (
        <div className="w-[310px] h-auto pb-5  p-4 bg-gray-600 border border-gray-500 rounded-xl flex flex-col items-center justify-between">
            <div className="w-full h-1/2 flex flex-col items-center justify-center">
                <img src={image}className="w-44 h-44" />
            </div>
            <div className="w-full h-1/2 flex flex-col gap-2 pt-2">
                <label className="text-white font-bold text-lg">{title}</label>
                <p className="text-gray-200 font-normal text-sm">{description}</p>
                <div className="w-full h-1/3 flex items-center justify-between">
                    <label className="text-emerald-500 font-bold text-lg">${price}</label>
                    <button className="bg-violet-600 rounded-sm flex items-center justify-center font-bold text-white p-2 text-xs w-16 h-8">View</button>
                </div>
            </div>

        </div>
    )
}

export default Product
