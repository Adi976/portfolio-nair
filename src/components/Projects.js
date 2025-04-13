import React from 'react';
import styled from 'styled-components';
import { motion } from 'framer-motion';
import { useInView } from 'react-intersection-observer';
import { FaGithub } from 'react-icons/fa';

const ProjectsSection = styled.section`
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

const ProjectsGrid = styled.div`
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(350px, 1fr));
  gap: 40px;
  max-width: 1200px;
  margin: 0 auto;
  padding: 0 20px;
`;

const ProjectCard = styled(motion.div)`
  background: white;
  border-radius: 12px;
  overflow: hidden;
  box-shadow: 0 10px 30px rgba(0, 0, 0, 0.1);
  transition: ${({ theme }) => theme.transition};

  &:hover {
    transform: translateY(-10px);
    box-shadow: 0 20px 40px rgba(0, 0, 0, 0.15);
  }
`;

const ProjectImage = styled.div`
  height: 200px;
  background-size: cover;
  background-position: center;
  position: relative;
`;

const ProjectContent = styled.div`
  padding: 30px;
`;

const ProjectTitle = styled.h3`
  font-size: 1.5rem;
  margin-bottom: 15px;
  color: ${({ theme }) => theme.colors.text};
`;

const ProjectDescription = styled.p`
  color: #666;
  margin-bottom: 20px;
  line-height: 1.6;
`;

const ProjectTags = styled.div`
  display: flex;
  flex-wrap: wrap;
  gap: 10px;
  margin-bottom: 20px;
`;

const Tag = styled.span`
  background: ${({ theme }) => theme.colors.lightBg};
  color: ${({ theme }) => theme.colors.accent};
  padding: 6px 12px;
  border-radius: 20px;
  font-size: 0.85rem;
  font-weight: 500;
`;

const ProjectLinks = styled.div`
  display: flex;
  gap: 15px;
`;

const ProjectLink = styled(motion.a)`
  display: inline-flex;
  align-items: center;
  gap: 8px;
  color: ${({ theme }) => theme.colors.accent};
  text-decoration: none;
  font-weight: 500;
  transition: ${({ theme }) => theme.transition};

  &:hover {
    color: ${({ theme }) => theme.colors.primary};
  }
`;

const Projects = () => {
  const [ref, inView] = useInView({
    triggerOnce: true,
    threshold: 0.1,
  });

  const projects = [
    {
      title: 'Audio Separator',
      description: 'Created a tool for separating vocals and instrumentals from audio files using deep learning models like Demucs. Built a simple interface for karaoke generation.',
      tags: ['Flask', 'Spleeter', 'Demucs', 'Python'],
      image: '/Audio.jpeg',
      github: 'https://github.com/Adi976/AudioSeparator'
    },
    {
      title: 'Story Pals',
      description: 'An interactive, conversational storytelling platform that engages children with AI-driven conversations, fostering learning, creativity, and emotional development. Integrated built-in parental controls and monitoring features.',
      tags: ['Ollama', 'Flutter', 'AI', 'EdTech'],
      image: '/Story.jpg',
      github: 'https://github.com/Adi976/Story-Pals'
    },
    {
      title: 'Movie Recommender',
      description: 'Developed a personalized movie recommendation system using collaborative filtering to suggest movies based on user preferences and ratings. The system processes the OMDb database to provide tailored suggestions and enhance the user experience.',
      tags: ['React','Django','Ollama'],
      image: '/Movie.jpg',
      github: 'https://github.com/Adi976/Movie-Recommender'
    }
  ];

  return (
    <ProjectsSection id="projects">
      <SectionTitle
        ref={ref}
        initial={{ opacity: 0, y: 20 }}
        animate={inView ? { opacity: 1, y: 0 } : {}}
        transition={{ duration: 0.5 }}
      >
        Projects
      </SectionTitle>
      <ProjectsGrid>
        {projects.map((project, index) => (
          <ProjectCard
            key={project.title}
            initial={{ opacity: 0, y: 20 }}
            animate={inView ? { opacity: 1, y: 0 } : {}}
            transition={{ duration: 0.5, delay: index * 0.1 }}
          >
            <ProjectImage 
              style={{ 
                backgroundImage: `url(${process.env.PUBLIC_URL + project.image})`,
                backgroundSize: 'cover',
                backgroundPosition: 'center'
              }}
              onError={(e) => {
                console.error('Image failed to load:', e);
                console.log('Attempted to load from:', process.env.PUBLIC_URL + project.image);
                e.target.style.border = '2px solid red';
              }}
              onLoad={() => console.log('Image loaded successfully')}
            />
            <ProjectContent>
              <ProjectTitle>{project.title}</ProjectTitle>
              <ProjectDescription>{project.description}</ProjectDescription>
              <ProjectTags>
                {project.tags.map((tag, index) => (
                  <Tag key={index}>{tag}</Tag>
                ))}
              </ProjectTags>
              <ProjectLinks>
                <ProjectLink
                  href={project.github}
                  target="_blank"
                  rel="noopener noreferrer"
                  whileHover={{ scale: 1.05 }}
                  whileTap={{ scale: 0.95 }}
                >
                  <FaGithub />
                  View on GitHub
                </ProjectLink>
              </ProjectLinks>
            </ProjectContent>
          </ProjectCard>
        ))}
      </ProjectsGrid>
    </ProjectsSection>
  );
};

export default Projects; 