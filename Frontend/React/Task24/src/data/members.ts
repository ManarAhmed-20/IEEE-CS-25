export interface Member {
  id: number;
  name: string;
  role: string;
  department: string;
  avatarUrl: string;
  email: string;
  linkedin?: string;
  bio: string;
  joinedDate: string;
}
export const members: Member[] = [
  {
    id: 1,
    name: "Tarek Mansour",
    role: "Team Lead",
    department: "Management",
    avatarUrl: "https://randomuser.me/api/portraits/men/21.jpg",
    email: "tarek@example.com",
    linkedin: "https://linkedin.com/in/tarek-mansour",
    bio: "Visionary team leader with a drive for innovation and collaboration.",
    joinedDate: "2022-01-15",
  },
  {
    id: 2,
    name: "Omar Youssef",
    role: "Frontend Developer",
    department: "Engineering",
    avatarUrl: "https://randomuser.me/api/portraits/men/9.jpg",
    email: "omar@example.com",
    bio: "Frontend developer with a love for clean UI and reusable components.",
    joinedDate: "2023-03-10",
  },
  {
    id: 3,
    name: "Khaled Hassan",
    role: "Backend Developer",
    department: "Engineering",
    avatarUrl: "https://randomuser.me/api/portraits/men/18.jpg",
    email: "khaled@example.com",
    linkedin: "https://linkedin.com/in/khaled-hassan",
    bio: "Node.js and database enthusiast with strong focus on scalability.",
    joinedDate: "2023-02-22",
  },
  {
    id: 4,
    name: "Nader Hossam",
    role: "UI/UX Designer",
    department: "Design",
    avatarUrl: "https://randomuser.me/api/portraits/men/41.jpg",
    email: "nader@example.com",
    bio: "Creative designer focused on user-centered digital experiences.",
    joinedDate: "2022-11-01",
  },
  {
    id: 5,
    name: "Youssef Tamer",
    role: "DevOps Engineer",
    department: "Infrastructure",
    avatarUrl: "https://randomuser.me/api/portraits/men/20.jpg",
    email: "youssef@example.com",
    linkedin: "https://linkedin.com/in/youssef-tamer",
    bio: "Automating deployments and optimizing cloud performance.",
    joinedDate: "2024-01-05",
  },
  {
    id: 6,
    name: "Mohamed Ali",
    role: "QA Engineer",
    department: "Quality Assurance",
    avatarUrl: "https://randomuser.me/api/portraits/men/63.jpg",
    email: "mohamed@example.com",
    bio: "Ensuring quality through automation and meticulous testing.",
    joinedDate: "2023-05-18",
  },
];
