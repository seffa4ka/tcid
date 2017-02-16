<?php

/**
 * @file
 * Class NodeLogEntityMetadataController.
 */

/**
 * Extends EntityDefaultMetadataController.
 */
class NodeLogEntityMetadataController extends EntityDefaultMetadataController {

  /**
   * It describes the entity.
   *
   * Linked node_log_entity with node and user. Processing timestamp.
   *
   * @return array
   *   Property info.
   */
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $info[$this->type]['properties']['node'] = array(
      'label' => t("Node"),
      'type' => 'node',
      'description' => t("Node"),
      'schema field' => 'nid',
    );
    $info[$this->type]['properties']['user'] = array(
      'label' => t("User ID"),
      'type' => 'user',
      'description' => t("User ID"),
      'schema field' => 'uid',
    );
    $info[$this->type]['properties']['timestamp'] = array(
      'label' => t("timestamp"),
      'type' => 'date',
      'description' => t("timestamp"),
      'schema field' => 'timestamp',
      'setter callback' => 'entity_property_verbatim_set',
    );
    return $info;
  }

}
