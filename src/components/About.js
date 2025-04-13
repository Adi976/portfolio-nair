import React from 'react';
import styled from 'styled-components';
import { motion } from 'framer-motion';
import { useInView } from 'react-intersection-observer';

const AboutSection = styled.section`
  padding: ${props => props.theme.spacing.xl} 0;
  background-color: ${props => props.theme.colors.white};

  @media (max-width: ${props => props.theme.breakpoints.tablet}) {
    padding: ${props => props.theme.spacing.lg} 0;
  }
`;

const SectionTitle = styled(motion.h2)`
  font-size: 3rem;
  text-align: center;
  margin-bottom: ${props => props.theme.spacing.xl};
  font-weight: 700;
  position: relative;

  @media (max-width: ${props => props.theme.breakpoints.tablet}) {
    font-size: 2.5rem;
    margin-bottom: ${props => props.theme.spacing.lg};
  }

  @media (max-width: ${props => props.theme.breakpoints.mobile}) {
    font-size: 2rem;
    margin-bottom: ${props => props.theme.spacing.md};
  }
`;

const AboutContent = styled.div`
  display: grid;
  grid-template-columns: 1fr;
  gap: ${props => props.theme.spacing.xl};
  max-width: 800px;
  margin: 0 auto;
  padding: 0 ${props => props.theme.spacing.md};

  @media (max-width: ${props => props.theme.breakpoints.tablet}) {
    padding: 0 ${props => props.theme.spacing.sm};
    gap: ${props => props.theme.spacing.lg};
  }
`;

const AboutText = styled(motion.div)`
  p {
    font-size: 1.1rem;
    margin-bottom: ${props => props.theme.spacing.md};
    color: #666;
    line-height: 1.8;

    @media (max-width: ${props => props.theme.breakpoints.tablet}) {
      font-size: 1rem;
      line-height: 1.6;
    }

    @media (max-width: ${props => props.theme.breakpoints.mobile}) {
      font-size: 0.95rem;
    }
  }
`;

const SkillsGrid = styled.div`
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
  gap: 30px;
  margin-top: 40px;

  @media (max-width: ${props => props.theme.breakpoints.tablet}) {
    gap: 20px;
    margin-top: 30px;
  }

  @media (max-width: ${props => props.theme.breakpoints.mobile}) {
    grid-template-columns: 1fr;
    gap: 15px;
  }
`;

const SkillCategory = styled(motion.div)`
  background: white;
  padding: 25px;
  border-radius: 12px;
  box-shadow: 0 5px 15px rgba(0, 0, 0, 0.05);
  transition: ${({ theme }) => theme.transition};

  @media (max-width: ${props => props.theme.breakpoints.mobile}) {
    padding: 20px;
  }

  &:hover {
    transform: translateY(-5px);
    box-shadow: 0 10px 25px rgba(0, 0, 0, 0.1);
  }

  h5 {
    color: ${({ theme }) => theme.colors.accent};
    font-size: 1.1rem;
    margin-bottom: 15px;
    display: flex;
    align-items: center;
    gap: 10px;

    @media (max-width: ${props => props.theme.breakpoints.mobile}) {
      font-size: 1rem;
      margin-bottom: 12px;
    }
  }

  ul {
    list-style: none;
    padding: 0;
    display: flex;
    flex-wrap: wrap;
    gap: 10px;

    @media (max-width: ${props => props.theme.breakpoints.mobile}) {
      gap: 8px;
    }
  }

  li {
    background: ${({ theme }) => theme.colors.lightBg};
    color: ${({ theme }) => theme.colors.text};
    padding: 8px 15px;
    border-radius: 20px;
    font-size: 0.9rem;
    font-weight: 500;
    transition: ${({ theme }) => theme.transition};

    @media (max-width: ${props => props.theme.breakpoints.mobile}) {
      padding: 6px 12px;
      font-size: 0.85rem;
    }

    &:hover {
      background: ${({ theme }) => theme.colors.accent};
      color: white;
    }
  }
`;

const About = () => {
  const [ref, inView] = useInView({
    threshold: 0.1,
    triggerOnce: true,
  });

  const skills = {
    'Programming Languages': ['Java', 'Python', 'C++', 'SQL'],
    'Web Development': ['Bootstrap', 'React.js', 'Flask'],
    'Machine Learning': [ 'PyTorch', 'Scikit-learn'],
    'Tools & Technologies': ['Azure', 'Flutter', 'Ollama']
  };

  const containerVariants = {
    hidden: { opacity: 0 },
    visible: {
      opacity: 1,
      transition: {
        staggerChildren: 0.1,
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
              I am a passionate and driven student with a strong foundation in Java, Python, and Machine Learning. With a deep interest in solving real-world problems, I strive to build technology that is both practical and impactful.
            </motion.p>
            <motion.p variants={itemVariants}>
              My project experience spans audio processing, edtech, and recommendation systems, reflecting a clear focus on creating human-centered solutions. I bring a problem-solving mindset, a collaborative spirit, and a positive, perseverant attitude that fuels my drive to keep learning and building with purpose.
            </motion.p>
          </AboutText>
          <SkillsGrid
            variants={containerVariants}
            initial="hidden"
            animate={inView ? "visible" : "hidden"}
          >
            {Object.entries(skills).map(([category, items]) => (
              <SkillCategory key={category} variants={itemVariants}>
                <h5>{category}</h5>
                <ul>
                  {items.map((skill, index) => (
                    <li key={index}>{skill}</li>
                  ))}
                </ul>
              </SkillCategory>
            ))}
          </SkillsGrid>
        </AboutContent>
      </div>
    </AboutSection>
  );
};

export default About; 