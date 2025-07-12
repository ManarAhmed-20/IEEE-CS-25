import type { Member } from "../../data/members";
import './Card.css'
type Props = {
  member: Member;
};

const Card = ({ member }: Props) => {
  return (
    <div className="w-96 text-center h-80 drop-shadow-sm border-gray-100 border bg-white rounded-2xl flex flex-col justify-between items-center p-4 hover:border-blue-500 hover:drop-shadow-xl">
      <img src={member.avatarUrl} alt={member.name} className="w-24 h-24 border-2 border-blue-500 rounded-full object-cover" />
      <h2 className="text-gray-800 font-bold text-xl">{member.name}</h2>
      <label className="text-gray-400 font-normal text-md">{member.role} — {member.department}</label>
      <p className="text-gray-800 font-normal text-sm">{member.bio}</p>
      <label className="text-gray-400 font-light text-xs">Joined on {member.joinedDate}</label>
      <div className="flex gap-2 mt-4">
        <a href={member.email}>
          <button className="bg-blue-500 text-white rounded-3xl px-4 py-1 text-sm">Email</button>
        </a>
        {member.linkedin && (
          <a href={member.linkedin}>
            <button className="text-blue-500 text-sm">LinkedIn</button>
          </a>
        )}
      </div>
    </div>
  );
};

export default Card;