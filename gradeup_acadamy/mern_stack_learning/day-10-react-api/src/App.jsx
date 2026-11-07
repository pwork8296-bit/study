import { useState } from 'react'
import MapDemo from './components/MapDemo'
import FetchDemo from './components/FetchDemo'
import './App.css'

function App() {
  const [currentTab, setCurrentTab] = useState('fetch')

  return (
    <>
      {/* Top Navigation between Day 8 Concepts */}
      <nav className="app-nav-bar" aria-label="Course Topic Navigation">
        <button
          type="button"
          className={`app-nav-pill ${currentTab === 'map' ? 'active' : ''}`}
          onClick={() => setCurrentTab('map')}
        >
          🗺️ Map Function Demo
        </button>
        <button
          type="button"
          className={`app-nav-pill ${currentTab === 'fetch' ? 'active' : ''}`}
          onClick={() => setCurrentTab('fetch')}
        >
          ⚡ Fetch API Demo (DummyJSON)
        </button>
      </nav>

      {/* Active Component */}
      <main>
        {currentTab === 'fetch' ? <FetchDemo /> : <MapDemo />}
      </main>
    </>
  )
}

export default App
