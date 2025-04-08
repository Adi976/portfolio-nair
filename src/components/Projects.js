import React, { useState } from 'react';
import styled from 'styled-components';
import { motion, AnimatePresence } from 'framer-motion';
import { useInView } from 'react-intersection-observer';
import { FaFilter, FaTimes, FaChevronLeft, FaChevronRight } from 'react-icons/fa';

const ProjectsSection = styled.section`
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

const FilterContainer = styled.div`
  display: flex;
  justify-content: center;
  gap: 20px;
  margin-bottom: 40px;
  flex-wrap: wrap;
`;

const FilterButton = styled(motion.button)`
  padding: 8px 16px;
  border: 2px solid ${({ theme, active }) => active ? theme.colors.accent : '#e0e0e0'};
  border-radius: 20px;
  background: ${({ active }) => active ? 'rgba(0, 113, 227, 0.1)' : 'transparent'};
  color: ${({ theme, active }) => active ? theme.colors.accent : '#666'};
  font-weight: 500;
  cursor: pointer;
  transition: all 0.3s ease;

  &:hover {
    border-color: ${({ theme }) => theme.colors.accent};
    color: ${({ theme }) => theme.colors.accent};
  }
`;

const ProjectGrid = styled.div`
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(350px, 1fr));
  gap: 40px;
`;

const ProjectCard = styled(motion.div)`
  background: white;
  border-radius: 12px;
  overflow: hidden;
  position: relative;
  box-shadow: 0 10px 20px rgba(0, 0, 0, 0.05);
`;

const ProjectImage = styled.div`
  height: 250px;
  background-size: cover;
  background-position: center;
  position: relative;
  cursor: pointer;
`;

const ProjectOverlay = styled(motion.div)`
  position: absolute;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  background: rgba(0, 0, 0, 0.5);
  display: flex;
  align-items: center;
  justify-content: center;
  opacity: 0;
`;

const ProjectInfo = styled.div`
  padding: 30px;
`;

const ProjectTitle = styled.h3`
  font-size: 1.5rem;
  margin-bottom: 15px;
  font-weight: 600;
  color: ${({ theme }) => theme.colors.text};
`;

const ProjectTags = styled.div`
  display: flex;
  flex-wrap: wrap;
  gap: 10px;
  margin-top: 20px;
`;

const Tag = styled.span`
  background-color: ${({ theme }) => theme.colors.lightBg};
  color: ${({ theme }) => theme.colors.accent};
  padding: 6px 12px;
  border-radius: 20px;
  font-size: 0.85rem;
  font-weight: 500;
`;

const Lightbox = styled(motion.div)`
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  background: rgba(0, 0, 0, 0.9);
  display: flex;
  align-items: center;
  justify-content: center;
  z-index: 1000;
`;

const LightboxImage = styled.img`
  max-width: 90%;
  max-height: 90vh;
  object-fit: contain;
`;

const LightboxControls = styled.div`
  position: absolute;
  top: 20px;
  right: 20px;
  display: flex;
  gap: 20px;
`;

const ControlButton = styled.button`
  background: transparent;
  border: none;
  color: white;
  font-size: 1.5rem;
  cursor: pointer;
  padding: 10px;
  display: flex;
  align-items: center;
  justify-content: center;
`;

const projects = [
  {
    id: 1,
    title: 'AI-Powered Image Recognition',
    description: 'A deep learning model that can accurately classify and detect objects in real-time using computer vision techniques.',
    tags: ['Python', 'TensorFlow', 'OpenCV', 'Machine Learning'],
    images: [
      'https://source.unsplash.com/random/800x600?ai1',
      'https://source.unsplash.com/random/800x600?ai2',
      'https://source.unsplash.com/random/800x600?ai3'
    ]
  },
  {
    id: 2,
    title: 'Predictive Analytics Dashboard',
    description: 'An interactive dashboard that uses machine learning to predict trends and provide actionable insights from complex datasets.',
    tags: ['React', 'Python', 'D3.js', 'Data Analysis'],
    images: [
      'https://source.unsplash.com/random/800x600?data1',
      'https://source.unsplash.com/random/800x600?data2',
      'https://source.unsplash.com/random/800x600?data3'
    ]
  },
  {
    id: 3,
    title: 'Natural Language Processing API',
    description: 'A RESTful API that processes and analyzes text data using advanced NLP techniques and machine learning models.',
    tags: ['Python', 'FastAPI', 'NLTK', 'NLP'],
    images: [
      'https://source.unsplash.com/random/800x600?nlp1',
      'https://source.unsplash.com/random/800x600?nlp2',
      'https://source.unsplash.com/random/800x600?nlp3'
    ]
  }
];

const Projects = () => {
  const [ref, inView] = useInView({
    triggerOnce: true,
    threshold: 0.1,
  });

  const [activeFilter, setActiveFilter] = useState('All');
  const [lightboxOpen, setLightboxOpen] = useState(false);
  const [currentImage, setCurrentImage] = useState(null);
  const [currentProject, setCurrentProject] = useState(null);

  const allTags = ['All', ...new Set(projects.flatMap(project => project.tags))];

  const filteredProjects = activeFilter === 'All'
    ? projects
    : projects.filter(project => project.tags.includes(activeFilter));

  const openLightbox = (project, image) => {
    setCurrentProject(project);
    setCurrentImage(image);
    setLightboxOpen(true);
  };

  const closeLightbox = () => {
    setLightboxOpen(false);
    setCurrentImage(null);
    setCurrentProject(null);
  };

  const nextImage = () => {
    const currentIndex = currentProject.images.indexOf(currentImage);
    const nextIndex = (currentIndex + 1) % currentProject.images.length;
    setCurrentImage(currentProject.images[nextIndex]);
  };

  const prevImage = () => {
    const currentIndex = currentProject.images.indexOf(currentImage);
    const prevIndex = (currentIndex - 1 + currentProject.images.length) % currentProject.images.length;
    setCurrentImage(currentProject.images[prevIndex]);
  };

  return (
    <ProjectsSection id="projects">
      <SectionTitle>Featured Projects</SectionTitle>
      <FilterContainer>
        {allTags.map(tag => (
          <FilterButton
            key={tag}
            active={activeFilter === tag}
            onClick={() => setActiveFilter(tag)}
            whileHover={{ scale: 1.05 }}
            whileTap={{ scale: 0.95 }}
          >
            {tag}
          </FilterButton>
        ))}
      </FilterContainer>
      <ProjectGrid ref={ref}>
        <AnimatePresence>
          {filteredProjects.map((project, index) => (
            <ProjectCard
              key={project.id}
              initial={{ opacity: 0, y: 20 }}
              animate={inView ? { opacity: 1, y: 0 } : {}}
              transition={{ duration: 0.5, delay: index * 0.1 }}
            >
              <ProjectImage
                style={{ backgroundImage: `url(${project.images[0]})` }}
                onClick={() => openLightbox(project, project.images[0])}
              >
                <ProjectOverlay
                  initial={{ opacity: 0 }}
                  whileHover={{ opacity: 1 }}
                >
                  <motion.button
                    whileHover={{ scale: 1.1 }}
                    whileTap={{ scale: 0.9 }}
                    style={{
                      background: 'white',
                      padding: '10px 20px',
                      borderRadius: '20px',
                      border: 'none',
                      cursor: 'pointer'
                    }}
                  >
                    View Gallery
                  </motion.button>
                </ProjectOverlay>
              </ProjectImage>
              <ProjectInfo>
                <ProjectTitle>{project.title}</ProjectTitle>
                <p>{project.description}</p>
                <ProjectTags>
                  {project.tags.map(tag => (
                    <Tag key={tag}>{tag}</Tag>
                  ))}
                </ProjectTags>
              </ProjectInfo>
            </ProjectCard>
          ))}
        </AnimatePresence>
      </ProjectGrid>

      <AnimatePresence>
        {lightboxOpen && (
          <Lightbox
            initial={{ opacity: 0 }}
            animate={{ opacity: 1 }}
            exit={{ opacity: 0 }}
          >
            <LightboxControls>
              <ControlButton onClick={prevImage}>
                <FaChevronLeft />
              </ControlButton>
              <ControlButton onClick={nextImage}>
                <FaChevronRight />
              </ControlButton>
              <ControlButton onClick={closeLightbox}>
                <FaTimes />
              </ControlButton>
            </LightboxControls>
            <LightboxImage
              src={currentImage}
              alt="Project"
              initial={{ scale: 0.8, opacity: 0 }}
              animate={{ scale: 1, opacity: 1 }}
              exit={{ scale: 0.8, opacity: 0 }}
            />
          </Lightbox>
        )}
      </AnimatePresence>
    </ProjectsSection>
  );
};

export default Projects; 