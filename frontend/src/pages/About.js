import React from 'react';
import './About.css';  // Import the CSS file

const About = () => {
  return (
    <div className="about-page">
      <div className="image1"></div>
      <div className="image2"></div>
      <div className="image3"></div>
      <div className="image4"></div>

      <div className="content">
        <h1>Poaching Detection System</h1>
        <a href="/code-project" className="code-project-link">Code Project</a>
      </div>
    </div>
  );
};

export default About;
