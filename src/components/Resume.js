import React from 'react';
import styled from 'styled-components';
import { motion } from 'framer-motion';
import { useInView } from 'react-intersection-observer';
import { FaDownload, FaGraduationCap, FaBriefcase, FaCertificate, FaCode } from 'react-icons/fa';

const ResumeSection = styled.section`
  padding: 120px 0;
  background-color: ${({ theme }) => theme.colors.lightBg};
`;

const SectionTitle = styled(motion.h2)`
  font-size: 3rem;
  text-align: center;
  margin-bottom: 80px;
  font-weight: 700;
  color: ${({ theme }) => theme.colors.text};
`;

const ResumePreview = styled(motion.div)`
  max-width: 800px;
  margin: 0 auto 60px;
  background: white;
  border-radius: 12px;
  box-shadow: 0 10px 30px rgba(0, 0, 0, 0.1);
  overflow: hidden;
  cursor: pointer;
  transition: ${({ theme }) => theme.transition};

  &:hover {
    transform: translateY(-5px);
    box-shadow: 0 15px 40px rgba(0, 0, 0, 0.15);
  }
`;

const PreviewHeader = styled.div`
  padding: 30px;
  background: ${({ theme }) => theme.colors.accent};
  color: white;
`;

const PreviewName = styled.h3`
  font-size: 2rem;
  margin-bottom: 10px;
`;

const PreviewContact = styled.div`
  display: flex;
  flex-wrap: wrap;
  gap: 20px;
  font-size: 0.9rem;
  opacity: 0.9;
`;

const PreviewContent = styled.div`
  padding: 30px;
`;

const PreviewSection = styled.div`
  margin-bottom: 30px;

  h4 {
    font-size: 1.2rem;
    color: ${({ theme }) => theme.colors.accent};
    margin-bottom: 15px;
    display: flex;
    align-items: center;
    gap: 10px;
  }

  p {
    color: #666;
    line-height: 1.6;
  }
`;

const DownloadButton = styled(motion.a)`
  display: inline-flex;
  align-items: center;
  gap: 10px;
  background-color: ${({ theme }) => theme.colors.accent};
  color: white;
  padding: 16px 32px;
  border-radius: 30px;
  font-weight: 500;
  text-decoration: none;
  margin: 0 auto;
  cursor: pointer;
  transition: ${({ theme }) => theme.transition};
  display: block;
  text-align: center;
  max-width: 250px;

  &:hover {
    transform: translateY(-2px);
    box-shadow: 0 10px 20px rgba(0, 113, 227, 0.2);
  }
`;

const SkillsGrid = styled.div`
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
  gap: 20px;
  margin-top: 20px;
`;

const SkillCategory = styled.div`
  h5 {
    color: ${({ theme }) => theme.colors.text};
    margin-bottom: 10px;
    font-size: 1rem;
  }

  ul {
    list-style: none;
    padding: 0;
  }

  li {
    color: #666;
    margin-bottom: 5px;
    display: flex;
    align-items: center;
    gap: 8px;

    &::before {
      content: '•';
      color: ${({ theme }) => theme.colors.accent};
    }
  }
`;

const Resume = () => {
  const [ref, inView] = useInView({
    triggerOnce: true,
    threshold: 0.1,
  });

  const education = [
    {
      institution: 'RNS Institute of Technology',
      degree: 'Bachelor of Engineering in Computer Science',
      period: 'Dec 2022– July 2026',
      details: 'CGPA: 8.96 (till 5th Sem)'
    },
    {
      institution: 'Hill Top School',
      degree: 'ISC Grade 12',
      period: 'June 2022',
      details: 'Percentage: 95%'
    },
    {
      institution: 'Hill Top School',
      degree: 'ICSE Grade 10',
      period: 'May 2020',
      details: 'Percentage: 90%'
    }
  ];

  const projects = [
    {
      title: 'Story Pals',
      tech: 'Ollama, Flutter',
      description: 'An interactive storytelling platform that engages children with AI-driven conversations, fostering learning, creativity, and emotional development. Integrated built-in parental controls and monitoring features.'
    },
    {
      title: 'Audio Separator',
      tech: 'Flask, Spleeter, Demucs',
      description: 'Created a tool for separating vocals and instrumentals from audio files using deep learning models like Demucs. Built a simple interface for karaoke generation.'
    }
  ];

  const certifications = [
    'Microsoft Azure Fundamentals',
    'Quantum Algorithms and Cryptography',
    'Introduction to Pytorch for Deep Learning',
    'Machine Learning Foundation'
  ];

  const skills = {
    'Languages': ['Java', 'Python', 'C++', 'SQL'],
    'Frameworks': ['Flask', 'React.js']
  };

  return (
    <ResumeSection id="resume">
      <SectionTitle
        ref={ref}
        initial={{ opacity: 0, y: 20 }}
        animate={inView ? { opacity: 1, y: 0 } : {}}
        transition={{ duration: 0.5 }}
      >
        Resume
      </SectionTitle>

      <ResumePreview
        initial={{ opacity: 0, y: 20 }}
        animate={inView ? { opacity: 1, y: 0 } : {}}
        transition={{ duration: 0.5, delay: 0.2 }}
        onClick={() => window.open('/Adithya Nair JX.pdf', '_blank')}
      >
        <PreviewHeader>
          <PreviewName>Adithya Nair</PreviewName>
          <PreviewContact>
            <span>+91 82107 65727</span>
            <span>adityaanil570@gmail.com</span>
            <a href="https://www.linkedin.com/in/adithya-nair-in" target="_blank" rel="noopener noreferrer">LinkedIn</a>
            <a href="https://github.com/Adi976" target="_blank" rel="noopener noreferrer">GitHub</a>
          </PreviewContact>
        </PreviewHeader>
        <PreviewContent>
          <PreviewSection>
            <h4><FaBriefcase /> Summary</h4>
            <p>
              I am a passionate and driven student with a strong foundation in Java, Python, and Machine Learning. 
              With a deep interest in solving real-world problems, I strive to build technology that is both practical 
              and impactful. My project experience spans audio processing, edtech, and recommendation systems, reflecting 
              a clear focus on creating human-centered solutions.
            </p>
          </PreviewSection>

          <PreviewSection>
            <h4><FaGraduationCap /> Education</h4>
            {education.map((edu, index) => (
              <div key={index} style={{ marginBottom: '15px' }}>
                <h5>{edu.institution}</h5>
                <p>{edu.degree}</p>
                <p style={{ color: '#666', fontSize: '0.9rem' }}>
                  {edu.period} | {edu.details}
                </p>
              </div>
            ))}
          </PreviewSection>

          <PreviewSection>
            <h4><FaCode /> Skills</h4>
            <SkillsGrid>
              {Object.entries(skills).map(([category, items]) => (
                <SkillCategory key={category}>
                  <h5>{category}</h5>
                  <ul>
                    {items.map((skill, index) => (
                      <li key={index}>{skill}</li>
                    ))}
                  </ul>
                </SkillCategory>
              ))}
            </SkillsGrid>
          </PreviewSection>
        </PreviewContent>
      </ResumePreview>

      <DownloadButton
        href="/Adithya Nair JX.pdf"
        download
        whileHover={{ scale: 1.05 }}
        whileTap={{ scale: 0.95 }}
      >
        <FaDownload />
        Download Full Resume
      </DownloadButton>
    </ResumeSection>
  );
};

export default Resume; 