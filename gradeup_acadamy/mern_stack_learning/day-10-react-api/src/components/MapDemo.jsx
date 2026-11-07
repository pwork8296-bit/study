import { useState } from 'react'
import './MapDemo.css'

// Initial data for array of objects demonstration
const initialStudents = [
  {
    id: 'std-101',
    name: 'Aarav Sharma',
    role: 'Full Stack MERN Dev',
    category: 'Full Stack',
    skills: ['React', 'Node.js', 'MongoDB', 'Express'],
    status: 'Active',
    avatar: 'AS',
  },
  {
    id: 'std-102',
    name: 'Priya Patel',
    role: 'Frontend Specialist',
    category: 'Frontend',
    skills: ['React', 'Tailwind', 'JavaScript', 'TypeScript'],
    status: 'Active',
    avatar: 'PP',
  },
  {
    id: 'std-103',
    name: 'Rohan Verma',
    role: 'Backend Engineer',
    category: 'Backend',
    skills: ['Node.js', 'Express', 'MongoDB', 'REST APIs'],
    status: 'Learning',
    avatar: 'RV',
  },
  {
    id: 'std-104',
    name: 'Sneha Kulkarni',
    role: 'UI/UX & React Dev',
    category: 'Frontend',
    skills: ['React', 'Figma', 'CSS3', 'Vite'],
    status: 'Active',
    avatar: 'SK',
  },
]

// Simple primitive array for basic list demo
const initialTechStack = [
  'HTML5',
  'CSS3',
  'JavaScript (ES6+)',
  'React.js',
  'Node.js',
  'Express.js',
  'MongoDB',
  'Git & GitHub',
]

export default function MapDemo() {
  const [activeTab, setActiveTab] = useState('objects') // 'basic' | 'objects' | 'interactive' | 'guide'

  // State for Interactive Demo
  const [studentsList, setStudentsList] = useState(initialStudents)
  const [selectedCategory, setSelectedCategory] = useState('All')
  const [searchQuery, setSearchQuery] = useState('')

  // State for Add Student Form
  const [newName, setNewName] = useState('')
  const [newRole, setNewRole] = useState('')
  const [newCategory, setNewCategory] = useState('Frontend')
  const [newSkills, setNewSkills] = useState('')

  // Handle Add Student
  const handleAddStudent = (e) => {
    e.preventDefault()
    if (!newName.trim() || !newRole.trim()) return

    const skillsArray = newSkills
      .split(',')
      .map((s) => s.trim())
      .filter(Boolean)

    const newStudent = {
      id: `std-${Date.now().toString().slice(-4)}`,
      name: newName.trim(),
      role: newRole.trim(),
      category: newCategory,
      skills: skillsArray.length > 0 ? skillsArray : ['React'],
      status: 'Active',
      avatar: newName
        .split(' ')
        .map((n) => n[0])
        .join('')
        .toUpperCase()
        .slice(0, 2),
    }

    // Adding item immutably
    setStudentsList([newStudent, ...studentsList])
    setNewName('')
    setNewRole('')
    setNewSkills('')
  }

  // Handle Delete Student
  const handleDeleteStudent = (idToDelete) => {
    // Demonstrating .filter() used to remove an element
    setStudentsList(studentsList.filter((student) => student.id !== idToDelete))
  }

  // Reset List
  const handleResetList = () => {
    setStudentsList(initialStudents)
    setSearchQuery('')
    setSelectedCategory('All')
  }

  // Filtered array (Demonstrates chaining .filter() and .map())
  const filteredStudents = studentsList.filter((student) => {
    const matchesCategory =
      selectedCategory === 'All' || student.category === selectedCategory
    const matchesSearch =
      student.name.toLowerCase().includes(searchQuery.toLowerCase()) ||
      student.role.toLowerCase().includes(searchQuery.toLowerCase()) ||
      student.skills.some((skill) =>
        skill.toLowerCase().includes(searchQuery.toLowerCase())
      )
    return matchesCategory && matchesSearch
  })

  return (
    <div className="map-demo-container">


      {/* Tabs */}
      <nav className="map-tabs" aria-label="Demo Views">
        <button
          type="button"
          className={`map-tab-btn ${activeTab === 'basic' ? 'active' : ''}`}
          onClick={() => setActiveTab('basic')}
        >
          1. Basic Array (.map)
        </button>
        <button
          type="button"
          className={`map-tab-btn ${activeTab === 'objects' ? 'active' : ''}`}
          onClick={() => setActiveTab('objects')}
        >
          2. Array of Objects & Nested Map
        </button>
      </nav>

      {/* Tab 1: Basic Primitive Array */}
      {activeTab === 'basic' && (
        <section className="map-section">

          {/* Code Preview */}
          <div className="code-preview-box">
            <span className="code-badge">JSX Syntax</span>
            <pre>
              {`{techStack.map((tech, index) => (
  <div key={tech} className="tag-item">
    <span className="tag-index">{index + 1}</span>
    <span>{tech}</span>
  </div>
))}`}
            </pre>
          </div>

          {/* Rendered elements with .map() */}
          <div className="tags-cloud">
            {initialTechStack.map((tech, index) => (
              <div key={tech} className="tag-item">
                <span className="tag-index-badge">{index + 1}</span>
                <span>{tech}</span>
              </div>
            ))}
          </div>

        </section>
      )}

      {/* Tab 2: Array of Objects & Nested Map */}
      {activeTab === 'objects' && (
        <section className="map-section">
          <div className="section-head">
            <div>
              <h3>Array of Objects with Nested .map()</h3>
              <p>
                Real-world React pattern: Top-level <code>.map()</code> creates
                the Student Cards, and an inner <code>.map()</code> renders the
                skills tag list inside each card.
              </p>
            </div>
          </div>

          <div className="code-preview-box">
            <span className="code-badge">Nested Map Example</span>
            <pre>
              {`{students.map((student) => (
  <div key={student.id} className="card-item">
    <h4>{student.name}</h4>
    {/* Nested .map() rendering skills array */}
    <div className="nested-skills">
      {student.skills.map((skill) => (
        <span key={skill} className="skill-chip">{skill}</span>
      ))}
    </div>
  </div>
))}`}
            </pre>
          </div>

          {/* Cards Grid generated via .map */}
          <div className="cards-grid">
            {initialStudents.map((student) => (
              <article key={student.id} className="card-item">
                <div className="card-top">
                  <div className="card-avatar">{student.avatar}</div>
                  <div className="card-info">
                    <h4 className="card-name">{student.name}</h4>
                    <p className="card-role">{student.role}</p>
                  </div>
                </div>

                <div className="card-details">
                  <div className="card-meta-row">
                    <span className="meta-label">Track:</span>
                    <strong style={{ color: 'var(--text-h)' }}>
                      {student.category}
                    </strong>
                  </div>

                  <div className="card-meta-row">
                    <span className="meta-label">Status:</span>
                    <span
                      className={`status-badge ${student.status === 'Active'
                        ? 'status-active'
                        : 'status-learning'
                        }`}
                    >
                      ● {student.status}
                    </span>
                  </div>

                  {/* Demonstration of Nested .map() */}
                  <span className="card-skills-label">
                    Skills (Nested .map):
                  </span>
                  <div className="nested-skills-list">
                    {student.skills.map((skill) => (
                      <span key={skill} className="nested-skill-chip">
                        {skill}
                      </span>
                    ))}
                  </div>
                </div>

                <div className="card-key-highlight">
                  key = "{student.id}"
                </div>
              </article>
            ))}
          </div>
        </section>
      )}

    </div>
  )
}
