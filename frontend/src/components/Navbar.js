import React, { useState } from 'react';
import { Link } from 'react-router-dom';
import './Navbar.css'; // Import the CSS for styling the navbar
import navBackground from '../pages/Assets/forest-background-2.jpg';

const Navbar = () => {
  const [showNavbar, setShowNavbar] = useState(false);

  // Event to show navbar
  const handleMouseEnter = () => {
    setShowNavbar(true);
  };

  // Event to hide navbar
  const handleMouseLeave = () => {
    setShowNavbar(false);
  };

  return (
    <div 
      className="navbar-container" 
      onMouseEnter={handleMouseEnter} 
      onMouseLeave={handleMouseLeave}
      style={{
        position: 'fixed',
        top: 0,
        left: 0,
        right: 0,
        height: showNavbar ? '80px' : '15px', // Adjust height based on hover
        transition: 'height 0.3s ease',
        backgroundImage: `url(${navBackground})`,
        backgroundSize: 'cover',
        backgroundPosition: 'center',
        overflow: 'hidden',
        zIndex:1000,
      }}
    >
      {showNavbar && (
        <nav className="navbar">
          <div className="navbar-logo">
            <h3>Detect the poachers we will</h3> {/* Logo can be customized here */}
          </div>
          <ul className="navbar-links">
            <li><Link to="/">Home</Link></li>
            <li><Link to="/code-project">Code Project</Link></li>
            <li><Link to="/team">Team</Link></li>
          </ul>
        </nav>
      )}
    </div>
  );
};

export default Navbar;
