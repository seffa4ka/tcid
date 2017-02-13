<?php

/**
 * @file
 * Entity discount views default file.
 */

/**
 * Implements hook_views_default_views().
 */
function entity_discount_views_default_views() {

  $view = new view();
  $view->name = 'discount';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entity_discount_discount';
  $view->human_name = 'Discount';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'discount' => 'discount',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'discount' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity discount entity: User name */
  $handler->display->display_options['relationships']['username']['id'] = 'username';
  $handler->display->display_options['relationships']['username']['table'] = 'entity_discount_discount';
  $handler->display->display_options['relationships']['username']['field'] = 'username';
  $handler->display->display_options['relationships']['username']['required'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'username';
  /* Field: Entity discount entity: Entity discount entity ID */
  $handler->display->display_options['fields']['discount']['id'] = 'discount';
  $handler->display->display_options['fields']['discount']['table'] = 'entity_discount_discount';
  $handler->display->display_options['fields']['discount']['field'] = 'discount';
  $handler->display->display_options['fields']['discount']['label'] = 'discount code';
  $handler->display->display_options['fields']['discount']['element_label_colon'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  $views[$view->name] = $view;

  return $views;
}
