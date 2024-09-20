import React from 'react';
import { BrowserRouter as Router, Route, Routes, Link } from 'react-router-dom';
import About from './pages/About';
import CodeProject from './pages/CodeProject';

function App() {
  return (
    <Router>
      <div>
        <nav>
          <ul>
            <li><Link to="/">About</Link></li>
            <li><Link to="/code-project">Code Project</Link></li>
          </ul>
        </nav>

        <Routes>
          <Route path="/" element={<About />} />
          <Route path="/code-project" element={<CodeProject />} />
        </Routes>
      </div>
    </Router>
  );
}

export default App;
