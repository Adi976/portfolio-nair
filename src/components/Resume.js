import React from 'react';
import styled from 'styled-components';
import { motion } from 'framer-motion';
import { useInView } from 'react-intersection-observer';
import { FaDownload, FaGraduationCap, FaBriefcase } from 'react-icons/fa';

const ResumeSection = styled.section`
  padding: 120px 0;
  background-color: ${({ theme }) => theme.colors.lightBg};
`;

const SectionTitle = styled.h2`
  font-size: 3rem;
  text-align: center;
  margin-bottom: 80px;
  font-weight: 700;
  color: ${({ theme }) => theme.colors.text};
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
  margin: 0 auto 80px;
  cursor: pointer;
  transition: all 0.3s ease;

  &:hover {
    transform: translateY(-2px);
    box-shadow: 0 10px 20px rgba(0, 113, 227, 0.2);
  }
`;

const TimelineContainer = styled.div`
  max-width: 800px;
  margin: 0 auto;
  position: relative;
  padding: 40px 0;

  &::before {
    content: '';
    position: absolute;
    top: 0;
    left: 50%;
    transform: translateX(-50%);
    width: 2px;
    height: 100%;
    background-color: ${({ theme }) => theme.colors.accent};
  }
`;

const TimelineItem = styled(motion.div)`
  position: relative;
  margin-bottom: 60px;
  width: 50%;
  padding: 20px;
  background: white;
  border-radius: 12px;
  box-shadow: 0 10px 20px rgba(0, 0, 0, 0.05);

  &:nth-child(odd) {
    margin-left: auto;
    padding-left: 40px;
  }

  &:nth-child(even) {
    margin-right: auto;
    padding-right: 40px;
  }

  &::before {
    content: '';
    position: absolute;
    top: 20px;
    width: 20px;
    height: 20px;
    background-color: ${({ theme }) => theme.colors.accent};
    border-radius: 50%;
  }

  &:nth-child(odd)::before {
    left: -10px;
  }

  &:nth-child(even)::before {
    right: -10px;
  }
`;

const TimelineIcon = styled.div`
  position: absolute;
  top: 20px;
  color: ${({ theme }) => theme.colors.accent};
  font-size: 1.5rem;
`;

const TimelineContent = styled.div`
  h3 {
    font-size: 1.5rem;
    margin-bottom: 10px;
    color: ${({ theme }) => theme.colors.text};
  }

  h4 {
    font-size: 1.1rem;
    color: ${({ theme }) => theme.colors.accent};
    margin-bottom: 10px;
  }

  p {
    color: #666;
    line-height: 1.6;
  }

  .date {
    font-size: 0.9rem;
    color: #999;
    margin-bottom: 10px;
  }
`;

const Resume = () => {
  const [ref, inView] = useInView({
    triggerOnce: true,
    threshold: 0.1,
  });

  const timelineItems = [
    {
      type: 'education',
      title: 'Bachelor of Technology',
      subtitle: 'Computer Science',
      date: '2020 - 2024',
      description: 'Specialized in Machine Learning and Artificial Intelligence. Participated in various hackathons and coding competitions.',
    },
    {
      type: 'experience',
      title: 'Machine Learning Intern',
      subtitle: 'Tech Company',
      date: 'Summer 2023',
      description: 'Worked on developing and implementing machine learning models for predictive analytics.',
    },
    {
      type: 'education',
      title: 'High School',
      subtitle: 'Science Stream',
      date: '2018 - 2020',
      description: 'Focused on Mathematics and Computer Science. Participated in various science fairs and competitions.',
    },
  ];

  return (
    <ResumeSection id="resume">
      <SectionTitle>Resume</SectionTitle>
      <DownloadButton
        href="/resume.pdf"
        download
        whileHover={{ scale: 1.05 }}
        whileTap={{ scale: 0.95 }}
      >
        <FaDownload />
        Download CV
      </DownloadButton>
      <TimelineContainer ref={ref}>
        {timelineItems.map((item, index) => (
          <TimelineItem
            key={index}
            initial={{ opacity: 0, x: index % 2 === 0 ? -50 : 50 }}
            animate={inView ? { opacity: 1, x: 0 } : {}}
            transition={{ duration: 0.5, delay: index * 0.2 }}
          >
            <TimelineIcon>
              {item.type === 'education' ? <FaGraduationCap /> : <FaBriefcase />}
            </TimelineIcon>
            <TimelineContent>
              <h3>{item.title}</h3>
              <h4>{item.subtitle}</h4>
              <div className="date">{item.date}</div>
              <p>{item.description}</p>
            </TimelineContent>
          </TimelineItem>
        ))}
      </TimelineContainer>
    </ResumeSection>
  );
};

export default Resume; 