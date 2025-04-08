import React from 'react';
import styled from 'styled-components';
import { motion } from 'framer-motion';
import { useInView } from 'react-intersection-observer';

const AboutSection = styled.section`
  padding: ${props => props.theme.spacing.xl} 0;
  background-color: ${props => props.theme.colors.white};
`;

const SectionTitle = styled(motion.h2)`
  font-size: 3rem;
  text-align: center;
  margin-bottom: ${props => props.theme.spacing.xl};
  font-weight: 700;
  position: relative;

  @media (max-width: ${props => props.theme.breakpoints.mobile}) {
    font-size: 2.5rem;
  }
`;

const AboutContent = styled.div`
  display: grid;
  grid-template-columns: 1fr 1fr;
  gap: ${props => props.theme.spacing.xl};
  align-items: center;

  @media (max-width: ${props => props.theme.breakpoints.tablet}) {
    grid-template-columns: 1fr;
  }
`;

const AboutText = styled(motion.div)`
  p {
    font-size: 1.1rem;
    margin-bottom: ${props => props.theme.spacing.md};
    color: #666;
  }
`;

const Skills = styled(motion.div)`
  display: grid;
  gap: ${props => props.theme.spacing.md};
`;

const SkillItem = styled(motion.div)`
  background: ${props => props.theme.colors.lightBg};
  padding: ${props => props.theme.spacing.md};
  border-radius: ${props => props.theme.spacing.sm};
  transition: ${props => props.theme.transitions.default};

  &:hover {
    transform: translateY(-5px);
    box-shadow: ${props => props.theme.shadows.medium};
  }
`;

const SkillName = styled.div`
  display: flex;
  justify-content: space-between;
  margin-bottom: ${props => props.theme.spacing.sm};
  font-weight: 600;
`;

const SkillBar = styled.div`
  height: 8px;
  background-color: #e0e0e0;
  border-radius: 4px;
  overflow: hidden;
`;

const SkillLevel = styled(motion.div)`
  height: 100%;
  background: linear-gradient(90deg, ${props => props.theme.colors.accent}, #00a2ff);
  border-radius: 4px;
`;

const About = () => {
  const [ref, inView] = useInView({
    threshold: 0.1,
    triggerOnce: true,
  });

  const skills = [
    { name: 'Machine Learning', level: 90 },
    { name: 'Python', level: 85 },
    { name: 'Data Analysis', level: 80 },
    { name: 'Deep Learning', level: 75 },
  ];

  const containerVariants = {
    hidden: { opacity: 0 },
    visible: {
      opacity: 1,
      transition: {
        staggerChildren: 0.2,
      },
    },
  };

  const itemVariants = {
    hidden: { opacity: 0, y: 20 },
    visible: {
      opacity: 1,
      y: 0,
      transition: {
        duration: 0.5,
      },
    },
  };

  return (
    <AboutSection id="about">
      <div className="container">
        <SectionTitle
          ref={ref}
          initial={{ opacity: 0, y: 20 }}
          animate={inView ? { opacity: 1, y: 0 } : {}}
          transition={{ duration: 0.5 }}
        >
          About Me
        </SectionTitle>
        <AboutContent>
          <AboutText
            variants={containerVariants}
            initial="hidden"
            animate={inView ? "visible" : "hidden"}
          >
            <motion.p variants={itemVariants}>
              I'm a forward-thinking student with a deep passion for Artificial Intelligence and its potential to transform our world for the better. My journey in technology is driven by curiosity and a commitment to continuous learning.
            </motion.p>
            <motion.p variants={itemVariants}>
              I believe in the power of AI to solve complex problems and create meaningful impact. When I'm not immersed in code, you can find me exploring new technologies, contributing to open-source projects, or enjoying music.
            </motion.p>
          </AboutText>
          <Skills
            variants={containerVariants}
            initial="hidden"
            animate={inView ? "visible" : "hidden"}
          >
            {skills.map((skill, index) => (
              <SkillItem key={skill.name} variants={itemVariants}>
                <SkillName>
                  <span>{skill.name}</span>
                  <span>{skill.level}%</span>
                </SkillName>
                <SkillBar>
                  <SkillLevel
                    initial={{ width: 0 }}
                    animate={inView ? { width: `${skill.level}%` } : {}}
                    transition={{ duration: 1, delay: index * 0.2 }}
                  />
                </SkillBar>
              </SkillItem>
            ))}
          </Skills>
        </AboutContent>
      </div>
    </AboutSection>
  );
};

export default About; 