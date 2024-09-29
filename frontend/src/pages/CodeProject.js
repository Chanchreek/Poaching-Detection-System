import React from 'react';
import codeImage from './Assets/code-snippet-1.png';
import outputImage from './Assets/code-output-1.jpg';
import backgroundImage from './Assets/code-project-background.jpg';

const CodeProject = () => {
  return (
    <div className="code-output-wrapper" style={{ ...styles.wrapper, backgroundImage: `url(${backgroundImage})` }}>
      {/* Code Snippet Image */}
      <div className="code-section" style={styles.section}>
        <h2>Code Snippet</h2>
        <img
          src={codeImage}
          alt="Code Snippet"
          style={styles.image}
        />
      </div>

      {/* Output Image */}
      <div className="output-section" style={styles.section}>
        <h2>Code Output</h2>
        <img
          src={outputImage}
          alt="Code Output"
          style={styles.image}
        />
      </div>
    </div>
  );
};

const styles = {
  wrapper: {
    display: 'flex',
    justifyContent: 'space-between',
    alignItems: 'flex-start',
    gap: '20px',
    padding: '20px', // Optional padding
    backgroundSize: 'cover', // Ensures the background covers the entire area
    backgroundPosition: 'center', // Centers the background image
    height: '100vh', // Optional: Set height to fill the viewport
  },
  section: {
    width: '48%',
    backgroundColor: 'transparent', // Optional: Light background for better contrast
    borderRadius: '8px', // Optional: Rounded corners
    padding: '10px', // Optional padding for inner sections 
    color: 'white',
    fontSize: '15px',
  },
  image: {
    width: '100%',
    height: 'auto',
  },
};

export default CodeProject;
